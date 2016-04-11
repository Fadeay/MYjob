#-*- coding: UTF-8 -*-
import socket
import json
from time import strftime

from functions.Code import *
from functions.burst import *

cmddict={'enbase64':enbase64,'debase64':debase64,'hexdec':hexdec,'bindec':bindec,
        'octdec':octdec,'dechex':dechex,'binhex':binhex,'octhex':octhex,'decbin':decbin,
        'hexbin':hexbin,'octbin':octbin,'decoct':decoct,'hexoct':hexoct,'binoct':binoct,
        'md5md5':md5md5,'enurl':enurl,'deurl':deurl,'backdict':backdict,'burstback':burstback}
bind_ip   = "127.0.0.1"
bind_port = 51122
while True:
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((bind_ip,bind_port))
    server.listen(5)
    client,addr = server.accept()
    request = client.recv(1024)

    jsondata = json.loads(request)
    cmd = jsondata['cmd']
    msg = jsondata['msg']
    if jsondata['token'] != '7654123':
        server.close()
        client.close()
    try:
        data = cmddict[cmd](msg)
    except Exception, e:
        pass
    else:
        client.send(data)
        f = open('log.txt','a')
        f.writelines(strftime('%Y-%m-%d %H:%M:%S')+'    '+request+'    '+data+'  \n')
        f.close()
    finally:
        server.close()
        client.close()