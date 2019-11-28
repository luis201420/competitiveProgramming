import sys
import math

def isPrime(a):
    cont=0
    for i in range(2,int(math.sqrt(a))+1):
        if a%i==0:
            cont=cont+1
    return (cont == 0)

for line in sys.stdin:
    for n in line.split():
        if isPrime(int(n)):
            nr = n[::-1]
            if isPrime(int(nr)) and n!=nr:
                print(n+" is emirp.")
            else:
                print(n+" is prime.")
        else:
            print(n+" is not prime.")
