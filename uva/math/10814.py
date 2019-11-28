
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

n = int(input())
for i in range(n):
    l = input()
    a,l,b = l.split()
    a = int(a)
    b = int(b)
    g = gcd(a,b)
    print(str((a//g))+" / "+str((b//g)))
