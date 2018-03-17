import json
import sys
import socket
from datetime import datetime
import time
import struct


UDP_IP = "224.1.1.1"
UDP_PORT = 5007


s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
s.setsockopt(socket.IPPROTO_IP, socket.IP_MULTICAST_TTL, 10)

server = (UDP_IP, UDP_PORT)
#s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
#s.bind((ANY, UDP_PORT))
#mreq = struct.pack("4sl", socket.inet_aton(UDP_IP), socket.)
#s.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)
#s.listen(1)
#connection, client = s.accept()


times = datetime.now().strftime('%Y/%m/%d %H:%M:%S.%f')
data = {
    'size' : 10,
    'name' : 'TEST STREAM',
    'time' : times
}

#try:
#    thread.start_new_thread (time.sleep(20), ("Sleep_thread",1))
#except:
#    print ("Error: unable to start thread")

while True:
    time.sleep(0.25)
    data['size'] = 76
    data['time'] = datetime.now().strftime('%Y/%m/%d %H:%M:%S.%f')
    print ("time: " + data['time'] + "\n")
    json_data = json.dumps(data, separators=(',',':'))
    s.sendto(json_data.encode('utf-8'), server)
    
s.close()
