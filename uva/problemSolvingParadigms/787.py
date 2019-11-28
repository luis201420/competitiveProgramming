import sys

ns = []

for line in sys.stdin:
    for var in line.split():
        x = int(var)
        if x == -999999:
            ans = -1e500
            for i in range(len(ns)):
                s = 1
                for j in range(i,len(ns)):
                    s = s * ns[j]
                    ans = max(ans, s)
            print(ans)
            ns = []
        else:
            ns.append(x)
