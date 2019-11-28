n = int(input())

fib=[]
fib.append(0)
fib.append(1)
fib.append(1)

for i in range(3,n+1):
    fib.append(fib[i-1]+fib[i-3])

print(fib[n])


