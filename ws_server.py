import logging
import json
from random import randint
import multiprocessing
import time
from websocket_server import WebsocketServer as ws

#state = ["IDLE", "READY", "ACCEL", "COAST", "BRAKE"]

#msg = {
#    'acceleration' : 0,
#    'distance' : 0,
#    'velocity' : 0,
#    'propulsion_temp' : 45,
#    'braking_temp' : 119,
#    'motherboard_temp' : 38,
#    'pod_state': state[0]
#    }

msg = {
    'time': 1502399423,
    'type': "data",
    'name': 1,
    'data' : [45, 44.5, 45.5]
    }

def send_data(client, server):
    print("Sending data:")
    send_msg = json.dumps(msg, separators=(',',':'))
    server.send_message(client, send_msg)
    print(send_msg)

def new_client(client, server):
    print("New Client connected.\n")
    while True:
        process = multiprocessing.Process(target=send_data, args=(client, server))
        process.daemon = True
        process.start()


def new_cmd(client, server, message):
    msg_json = json.loads(message)
    #msg['levitation'] = msg_json['levitation']
    #msg['mag_r'] = msg_json['mag_speed']
    #msg['mag_l'] = msg_json['mag_speed']
    #msg['fr_drive'] = msg_json['fr_speed']
        
    #print(msg_json['levitation'])
    #print(msg_json['mag_speed'] + "\n")
    #print(msg_json['fr_speed'] + "\n")    

    

server = ws(6500, host='127.0.0.1')
try:
    print ('Server start')
    server.set_fn_new_client(new_client)
    server.set_fn_message_received(new_cmd)
    server.run_forever()
except:
    print ('Exception')
finally:
    for process in multiprocessing.active_children():
        process.terminate()
        process.join()
        print ('Goodbye')
