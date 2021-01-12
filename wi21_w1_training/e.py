import sys
n, m = tuple(map(int, input().split()))
g = [[] for _ in range(n+1)]
for i in range(m):
    u, v, w = tuple(map(int, input().split()))
    g[u].append((v, w, i+1)) # adj list
    g[v].append((u, w, i+1))
r = int(input())

def find_min(ds, visited):
    mnd = 100000000000000
    mnd_ind = -1
    for i in range(1, n+1):
        if not visited[i] and ds[i] < mnd:
            mnd_ind = i
            mnd = ds[i]
    return mnd_ind

# dijkstras
ds = [1000000000] * (n+1)
ds[r] = 0
visited = [False] * (n+1)
for _ in range(n):
    # update curr
    u = find_min(ds, visited)
    visited[u] = True
    # print(u)
    # if u == -1:
    #     sys.exit()

    # update distances
    for v, w, _ in g[u]:
        ds[v] = min(ds[v], ds[u] + w)
# print(ds)

# start adding edges
edges = []
wt = 0
for u in range(1, n+1):
    if u == r:
        continue
    mn = (0, 100000000000, 0)
    for v, w, i in g[u]:
        if w == ds[u] - ds[v] and w < mn[1]:
            mn = (v, w, i)
    edges.append(str(mn[2]))
    wt += mn[1]

# print results
print(wt)
print(' '.join(edges))