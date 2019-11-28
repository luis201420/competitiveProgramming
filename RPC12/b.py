import sys

ans = 0

for line in sys.stdin:
    l = line.split()[0]
    if l[0]=='|':
        ans+=(42*len(l))
    else:
        p = l.split(",-")
        x = int(p[0])
        ans += x*len(p[1])

print(str(ans+((10-ans%10)%10))+",-")
