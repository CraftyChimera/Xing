from pwnlib.util.fiddling import xor
a=bytes.fromhex("73626960647f6b206821204f21254f7d694f7624662065622127234f726927756d")
for i in range(256):
 m=xor(chr(i).encode(),a).decode()
 if "crypto" in m:
  print(m)
 print(chr(i))
