import requests
import sys

ip = '10.22'
for i in range(256):
    url0 = ip+'.'+str(i)
    for j in range(256):
        url = url0+'.'+str(j)
        try:
            r = requests.get('http://'+url,timeout=0.01)
            print url,r.status_code
        except:
            pass
