import base64
import md5
import urllib

def enbase64(msg):
    return base64.b64encode(msg['msg'])
    #return base64.encodestring(msg)

def debase64(msg):
    return base64.b64decode(msg['msg']+'='*(4-len(msg['msg'])%4))
#16-10
def hexdec(msg):
    return sre(int(msg['msg'],16))
#2-10
def bindec(msg):
    return str(int(msg['msg'], 2))
#8-10
def octdec(msg):
    return str(int(msg['msg'], 8))
#10-2
def decbin(msg):
    return bin(int(msg['msg']))
#16-2
def hexbin(msg):
    return bin(int(msg['msg'],16))
#8-2
def octbin(msg):
    return bin(int(msg['msg'],8))
#10-16
def dechex(msg):
    return hex(int(msg['msg']))
#8-16
def octhex(msg):
    return hex(int(msg['msg'], 8))
#2-16
def binhex(msg):
    return hex(int(msg['msg'],2))
#10-8
def decoct(msg):
    return oct(int(msg['msg']))
#16-8
def hexoct(msg):
    return oct(int(msg['msg'],16))
#2-8
def binoct(msg):
    return oct(int(msg['msg'],2))
#md5
def md5md5(msg):
    md532=md5.new()
    md532.update(msg['msg'])
    md532 = md532.hexdigest()
    md516 = md532[8:24]
    return md532+md516
def enurl(msg):
    return urllib.quote(msg['msg'])
def deurl(msg):
    return urllib.unquote(msg['msg'])
