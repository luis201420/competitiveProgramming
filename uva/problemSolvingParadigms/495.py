import sys

l=[0] * 5001
l[0]=0
l[1]=1

mayor=1

for line in sys.stdin:
    for n in line.split():
        n = int(n)

        if mayor<n:
            for i in range(2,n+1):
                l[i]=l[i-1]+l[i-2]

            mayor=n
        print ("The Fibonacci number for "+str(n)+" is "+str(l[n]))
