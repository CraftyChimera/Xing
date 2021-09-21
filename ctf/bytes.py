import base64
a=11515195063862318899931685488813747395775516287289682636499965282714637259206269
string=''
b=str(hex(a))[2:]
c=[]
print(b)
for i in range(len(b)//2):
 c.append(b[2*i:2*i+2])
for i in range(len(b)//2):
 print(c[i])
 x=bytes.fromhex(c[i])
 s=x.decode()
 string+=s
print(string)

