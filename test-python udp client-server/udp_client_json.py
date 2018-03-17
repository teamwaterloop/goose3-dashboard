import json
import sys
import socket
from datetime import datetime
import time
import struct

ANY = "0.0.0.0"
UDP_IP = "224.1.1.1"
UDP_PORT = 5007
server = (UDP_IP, UDP_PORT)

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM, socket.IPPROTO_UDP)
s.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
s.bind((ANY,UDP_PORT))
mreq = struct.pack("4sl", socket.inet_aton(UDP_IP), socket.INADDR_ANY)
s.setsockopt(socket.IPPROTO_IP, socket.IP_ADD_MEMBERSHIP, mreq)

#s.connect(server)
#s.bind(server)

data = s.recvfrom(1024)

while (data):
    data, addr = s.recvfrom(1024)#.decode('utf-8')
    json_data = json.loads(data.decode('utf-8'))
    time_data = datetime.strptime(json_data['time'],'%Y/%m/%d %H:%M:%S.%f')
    print(time_data.second,".",time_data.microsecond)

s.close()

    
    
