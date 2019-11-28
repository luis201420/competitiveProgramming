import sys

for line in sys.stdin:
    for var in line.split():
            var = int(var)
            var = var
            ant = 1
            cur = 1
            for i in range(0,var):
                aux=cur
                cur=ant+cur
                ant=aux
            print(cur)

