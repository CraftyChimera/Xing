from pwn import *
import Crypto.Util.number
import json
import base64
import codecs
r = remote('socket.cryptohack.org', 13377, level = 'debug')

def json_recv():
    line = r.recvline()
    return json.loads(line.decode())

def json_send(hsh):
    request = json.dumps(hsh).encode()
    r.sendline(request)

for x in range(100):
 received = json_recv()
 if received["type"] == "hex":
    a=bytes.fromhex(received["encoded"]).decode()
    
 if received["type"] == "bigint":
   b=received["encoded"]
   a=bytes.fromhex(received["encoded"][2:]).decode()
   
 if received["type"] == "base64":
   a=base64.b64decode(received["encoded"]).decode()
   
 if received["type"] == "utf-8":
   a=""
   b=received["encoded"]
   for x in b:
        a+=chr(x)
     
 if received["type"] == "rot13":
  a=codecs.decode(received["encoded"],"rot-13")
         
 print("Received type: ")
 print(received["type"])
 print("Received encoded value: ")
 print(received["encoded"])
 to_send = {
    "decoded": a}
 json_send(to_send)
a=json_recv()
print(a)