import sys

def binpow(a,b):
    r = 1
    while b>0:
        if b&1:
            r=r*a
        a=a*a
        b>>=1
    return r

def chartoInt(a):
    return ord(a)-48

def inttoChar(a):
    return chr(a+48)

def convBaseK(a,b):
    s = ""
    while a>=b:
        s=inttoChar(int(a%b))+s
        a=a//b
    return (inttoChar(a)+s)

def convBase10(a,b):
    r = 0
    for i in range(len(a)):
        r = r + (chartoInt(a[i])*binpow(b,len(a)-i-1))
    return r

for line in sys.stdin:
    if len(line.split())==1:
        break
    b,p,m = line.split()
    pd = convBase10(p,int(b))
    md = convBase10(m,int(b))
    res = pd%md
    res = convBaseK(res,int(b))
    print(res)
