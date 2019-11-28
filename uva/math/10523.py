import sys

def binpow(a,b):
    r = 1
    while b>0:
        if b&1:
            r = r*a
        a = a*a
        b>>=1
    return r

for line in sys.stdin:
    n,a = line.split()
    n = int(n)
    a = int(a)
    res = 0
    for i in range(1,n+1):
        res = res + i*binpow(a,i)
    print(res)
