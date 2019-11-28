import sys

def binpow(a,b):
    res = 1
    while b>0:
        if b&1:
            res = res*a
        a=a*a
        b>>=1
    return res

def convChartoInt(a):
    if 'A'<= a <= 'Z':
        return ord(a)-55
    else:
        return ord(a)-48

def greaterChar(a):
    ri = a[0]
    for i in range(1,len(a)):
        ri = max(a[i],ri)
    return ri

def convBase(a,b):
    r = 0
    p = len(a)
    for i in range(len(a)):
        r=r+(convChartoInt(a[i])*(binpow(b,p-i-1)))
    return r

for line in sys.stdin:
    x,y = line.split()
    gx = greaterChar(x)
    gy = greaterChar(y)
    gx = convChartoInt(gx)+1
    gy = convChartoInt(gy)+1
    gx = max(gx,2)
    gy = max(gy,2)
    ax = []
    res0 = res1 = -1
    for i in range(gx,37):
        ax.append(convBase(x,i))
    for i in range(gy,37):
        aux = convBase(y,i)
        for j in range(len(ax)):
            if aux==ax[j]:
                res0=j
                res1=i
                break
        if res0!=-1:
            break
    if res0!=-1 and res1!=1:
        print(x+" (base "+str(res0+gx)+") = "+y+" (base "+str(res1)+")")
    else:
        print(x+" is not equal to "+y+" in any base 2..36")
