import json
import sys
import socket
from datetime import datetime
import time

TCP_IP = "127.0.0.1"
TCP_PORT = 15000


s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server = (TCP_IP, TCP_PORT)
s.bind(server)
s.listen(1)
connection, client = s.accept()


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
    connection.sendall(json_data.encode('utf-8'))
    
s.close()
