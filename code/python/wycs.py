# -*- coding: utf-8 -*-
import requests
import re
from time import strftime

def woo(url, headers):

    website = "null"
    r = requests.get(url,headers=headers)

    try:
        website = re.findall("rel=\"nofollow\" href=\"(https?://[\w\.]*[/\w]*)",r.text)
    except AttributeError:
        print "NO DATA!"
    else:
        pass
    finally:
        return website


#payload = {'some': 'data'}
url = "http://www.wooyun.org/corps/"
headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; WOW64; rv:44.0) Gecko/20100101 Firefox/44.0'}
website = ""
filename = strftime('%Y-%m-%d %Hh%Mm') + ".txt"


r = requests.get(url,headers=headers)
try:
    webnum = re.search("<p class=\"page\">.+(\d{3}).+(\d{2})",r.text)
except AttributeError:
    print "NO DATA!"
else:
    print "Find " + webnum.group(1) + " data"
finally:
    pass



file = open(filename,"w")
for i in xrange(1,int(webnum.group(2))+1):
    urlpage = url + "page/" + str(i)
    weblist = woo(urlpage,headers)
    for x in weblist:
        file.writelines(x+"\n")

file.close()