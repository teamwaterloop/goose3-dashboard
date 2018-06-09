import logging
import json
from random import randint
import time
from websocket_server import WebsocketServer as ws

state = ["IDLE", "READY", "ACCEL", "COAST", "BRAKE"]

msg = {
    'acceleration' : 0,
    'distance' : 0,
    'velocity' : 0,
    'propulsion_temp' : 45,
    'braking_temp' : 119,
    'motherboard_temp' : 38,
    'pod_state': state[0]
    }

def send_data(client, server):
    print("New Client connected.\n")
    print("Sending data:")
    while server.clients:
        time.sleep(0.25)
        msg['acceleration']+=1
        msg['velocity']+=0.25*msg['acceleration']
        msg['distance']+=0.25*msg['velocity']
        msg['pod_state']=state[randint(0,4)]
        send_msg = json.dumps(msg,  separators=(',',':'))
        server.send_message(client, send_msg)
        print(send_msg)


def new_cmd(client, server, message):
    msg_json = json.loads(message)
    print(msg_json['levitation'] + "\n")
    print(msg_json['mag_speed'] + "\n")
    print(msg_json['fr_speed'] + "\n")    

    
json_message = json.dumps(msg)
server = ws(6500, host='127.0.0.1')
server.set_fn_new_client(send_data)
server.set_fn_message_received(new_cmd)
server.run_forever()
