import operator
def extgcd(a,b,u,v):
  if a%b == 0:
   return (b,v)
  else:
   c=a//b
   return extgcd(b,a%b,v,(u[0]-c*v[0],u[1]-c*v[1]))

a=26513
b=32321
gcd,bezout=extgcd(a,b,(1,0),(0,1))
print(gcd)
print(bezout)
