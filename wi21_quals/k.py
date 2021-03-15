import sys

n = int(input())
a = list(map(int, input().split()))
res = []

def nmax(a, k):
    m = -1
    mi = -1
    for i in range(len(a)):
        if i == k:
            continue
        if a[i] > m:
            m = a[i]
            mi = i
    return (m, mi)

if sum(a) % 2 == 1:
    print('no')
    sys.exit()
while sum(a) > 0:
    m1 = max(a)
    i = a.index(m1)
    m2, j = nmax(a, i)
    if m1 == 0 or m2 == 0:
        print('no')
        sys.exit()
    res.append([str(i+1), str(j+1)])
    a[i] -= 1
    a[j] -= 1
print('yes')
for r in res:
    print(' '.join(r))