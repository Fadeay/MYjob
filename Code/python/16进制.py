# -*- coding: utf-8 -*-  
a='1c10121a181e121a0f1016110b4d4d4d'
for i in range(0,len(a),2):
    b=255-int(a[i:i+2],16)
    if b>127:
        b-=128
    elif b<128:
        b+=128
    print chr(b),