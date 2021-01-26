import math
import sys

q = int(input())
res = []
for i in range(q):
    l, r = tuple(map(int, input().split()))
    ans = 0
    for p in range(2, 61):
        print(math.floor(r ** (1/p)), math.ceil(l ** (1/p)))
        ans += math.floor(r ** (1/p)) - math.ceil(l ** (1/p))
    res.append(ans)
for r in res:
    print(r)