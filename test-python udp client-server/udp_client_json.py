import json
import sys
import socket
from datetime import datetime
import time

UDP_IP = "localhost"
UDP_PORT = 12345

s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server = (UDP_IP, UDP_PORT)
#s.connect(server)
s.bind(server)

data = s.recvfrom(1024)

while (data):
    data, addr = s.recvfrom(1024)#.decode('utf-8')
    json_data = json.loads(data.decode('utf-8'))
    time_data = datetime.strptime(json_data['time'],'%Y/%m/%d %H:%M:%S.%f')
    print(time_data.second,".",time_data.microsecond)

s.close()

    
    
