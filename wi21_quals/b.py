import math
m, n, t = tuple(map(int, input().split()))
a = 1
if t == 1:
    while n > 0:
        a = n * a
        n -= 1
        if a > m:
            break
elif t == 2:
    a = 2**n
elif t == 3:
    a = n**4
elif t == 4:
    a = n**3
elif t == 5:
    a = n**2
elif t == 6:
    a = n * math.log2(n)
elif t == 7:
    a = n

if a > m:
    print("TLE")
else:
    print('AC')