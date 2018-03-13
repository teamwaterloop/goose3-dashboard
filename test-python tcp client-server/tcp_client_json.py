import json
import sys
import socket
from datetime import datetime
import time

TCP_IP = "127.0.0.1"
TCP_PORT = 15000

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server = (TCP_IP, TCP_PORT)
s.connect(server)

data = s.recv(1024)

while (data):
    data = s.recv(1024).decode('utf-8')
    json_data = json.loads(data)
    time_data = datetime.strptime(json_data['time'],'%Y/%m/%d %H:%M:%S.%f')
    print(time_data.second,".",time_data.microsecond)

s.close()

    
