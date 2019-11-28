t = int(input())

for i in range(t):
    n = int(input())
    s = 0
    p = 0
    while s<n:
        s+=(3**p)
        p+=1
    while p>=0:
        if (s-(3**p))>=n:
            s-=(3**p)
        p-=1
    print(s)
