import sys
import math

def binpowmod(a,b,m):
    a %= m
    res = 1
    while b>0:
        if b&1:
            res = res * a % m
        a = a * a % m
        b >>= 1
    return res

def isPrime(a):
    cont=0
    for i in range(2,int(math.sqrt(a))+1):
        if a%i==0:
            cont+=1
    return cont==0

for line in sys.stdin:
    p,a = line.split()
    p = int(p)
    a = int(a)
    if (p+a)==0:
        break
    res = binpowmod(a,p,p)
    if isPrime(p) or res!=a:
        print("no")
    else:
        print("yes")
