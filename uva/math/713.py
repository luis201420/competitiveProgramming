n = int(input())
for i in range(n):
    a,b = input().split()
    x = int(a[::-1])
    y = int(b[::-1])
    c = str(x+y)
    m = max(len(a),len(b))
    c = c[::-1]
    c = c + ('0'*(m-len(c)))
    c = int(c)
    print(c)
