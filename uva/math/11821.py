import sys
from decimal import *
from math import *

n = int(input())

for i in range(n):
    r = Decimal(0)
    for line in sys.stdin:
        if line == "0\n":
            break
        getcontext().prec = 50
        r = r + Decimal(line)
    
    res = "{:.50f}".format(r) 
    i = len(res)-1
    while res[i]=='0':
        i=i-1
    res = res[:i+1]
    if round(r,0)==r:
        print(round(r,0))
    else:
        print(res)
