import sys

for line in sys.stdin:
    for n in line.split():
        ni = int(n)
        if ni==0:
            break
        if ni < 10:
            print(0)
            continue
        l = int(n[len(n)-1])
        ni = int(n[:-1])
        print(int((ni-(5*l))%17==0))
