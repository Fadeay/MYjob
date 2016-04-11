# -*- coding: UTF-8 -*-
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

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((bind_ip,bind_port))
server.listen(5)
client,addr = server.accept()
request = client.recv(1024)

json = json.loads(request)
cmd = json['cmd']
msg = json['msg']
print cmd
print msg################

data = cmddict[cmd](msg)
print data
client.send(data)

server.close()
client.close()