import sys
n = int(input())
a = [set()]
for _ in range(n):
    a[0].add(input())

def rep(a):
    for s in a:
        if s == a[len(a)-1]:
            return True
    return False

def rp(s1, s2, pd, d):
    s = set()
    for c1 in s1:
        for c2 in s2:
            if len(c2) > len(c1) and c1 == c2[:len(c1)]:
                s.add(c2[len(c1):])
                d[c2[len(c1):]] = min(d.get(c2[len(c1):], 100000000000000), pd.get(c2, 0) + len(c1))
            elif len(c1) > len(c2) and c2 == c1[:len(c2)]:
                s.add(c1[len(c2):])
                d[c1[len(c2):]] = min(d.get(c1[len(c2):], 100000000000000), pd.get(c2, 0) + len(c2))
    return s

i = 1
pd, d = dict(), dict()
while True:
    if i == 1:
        s = rp(a[0], a[i-1], pd, d) - {0}
    else:
        s = rp(a[0], a[i-1], pd, d)
    # print(s, d)
    if len(s & a[0]) > 0:
        mc = 100000000000000
        for c in s & a[0]:
            mc = min(mc, d[c]+len(c))
        print(mc)
        sys.exit()
    for j in range(1, i):
        if s == a[j]:
            print(0)
            sys.exit()
    a.append(s)
    i += 1
    pd = d.copy()