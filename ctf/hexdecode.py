import base64
hex_string=input()
print(bytes.fromhex(hex_string))
a=base64.b64encode(bytes.fromhex(hex_string))
print(base64.b64decode(a))
