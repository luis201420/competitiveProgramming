import sys

def binpow(a,b):
    res = 1
    while b>0:
        if b&1:
            res = res*a
        a = a*a
        b>>=1
    return res

def inttoChar(a):
    if a<10:
        return chr(a+48)
    else:
        return chr(a+55)

def chartoInt(a):
    if a>='A' and a<='Z':
        return ord(a)-55
    else:
        return ord(a)-48

def convBase10(a,b):
    r = 0
    for i in range(len(a)):
        r = r + (chartoInt(a[i])*binpow(b,len(a)-i-1))
    return r

def convBaseK(a,b):
    s = ""
    while a>=b:
        s=inttoChar(int(a%b))+s
        a=a//b
    return (inttoChar(a)+s)

for line in sys.stdin:
    n,b1,b2 = line.split()
    ans=convBase10(n,int(b1))
    ans=convBaseK(ans,int(b2))
    if len(ans)>7:
        print("  ERROR")
    else:
        print((' '*(7-len(ans)))+ans)
