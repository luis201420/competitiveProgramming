import sys

for line in sys.stdin:
    for var in line.split():
            var = int(var)
            var = var
            ant = 0
            cur = 1
            for i in range(0,var):
                aux=cur
                cur=ant+cur
                ant=aux
            print("The Fibonacci number for "+str(var)+" is "+str(ant))

