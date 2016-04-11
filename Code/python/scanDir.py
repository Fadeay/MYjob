# -*- coding: utf-8 -*-

""" pure
import os
import re
from time import strftime

filename = strftime('%Y-%m-%d %Hh%Mm') + ".txt"
o=open(filename,"w")
o.close()
o=open(filename,"a")
rootdir = os.getcwd()



for parent, dirnames, filenames in os.walk(rootdir):
    for filename in filenames:
        o.writelines(filename+"\n")
o.close()
"""



import os,datetime

def getfilelist(filepath, tabnum=1):
    #simplepath = os.path.split(filepath)[1]
    returnstr = filepath+":\n"
    returndirstr = ""
    returnfilestr = ""
    filelist = os.listdir(filepath)
    for num in range(len(filelist)):
        filename=filelist[num]
        if os.path.isdir(filepath+"/"+filename):# and filename!='dist':###################################
            returndirstr += getfilelist(filepath+"/"+filename, tabnum+1)
        else:

            timestamp = os.path.getmtime(filepath+"/"+filename)
            date = datetime.datetime.fromtimestamp(timestamp)
            a=date.strftime('%Y-%m-%d %H:%M:%S')

            returnfilestr += "\t"*tabnum+a+'----'+filename+"\n"
    returnstr += returnfilestr+returndirstr
    return returnstr+"\t"*tabnum+"</>\n"

path = os.getcwd()
#path,b=os.path.split(path)#########################################
usefulpath = path.replace('\\', '/')
if usefulpath.endswith("/"):
    usefulpath = usefulpath[:-1]
if not os.path.exists(usefulpath):
    print "路径错误!"
elif not os.path.isdir(usefulpath):
    print "输入的不是目录!"
else:
    filelist = os.listdir(usefulpath)
    o=open("test.txt","w+")
    o.writelines(getfilelist(usefulpath))
    o.close()
    print "成功！请查看test文件"




