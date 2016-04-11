# -*- coding: utf-8 -*-  
a = '102,98,108,106,119,114'
aa = ""
b = a.split(',')
for x in b:
     aa += chr(int(x))
print aa
b = "from"
bb = ""
for x in b:
    bb += str(ord(x))+','
print bb