def gcd(a,b):
    while b:
        a%=b
        aux=a
        a=b
        b=aux
    return a

n = int(input())

res = 1

for i in range(2,n+1):
    res = (res*i)/gcd(res,i)

print(res)
