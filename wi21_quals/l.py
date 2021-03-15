t = int(input())
for _ in range(t):
    n = int(input())
    a = sorted(tuple(map(int, input().split())))
    ans = sum(a[n:3*n:2])
    print(ans)