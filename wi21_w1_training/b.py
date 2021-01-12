def dfs(a, curr, start, sm, mn, mx):
    count = 0
    if sm > r:
        return count
    if len(curr) >= 2 and sm >= l and sm <= r and (mx - mn) >= x:
        # print(curr)
        count += 1
    if start == len(a):
        return count
    else:
        for i in range(start, len(a)):
            count += dfs(a, curr + [a[i]], i+1, sm + a[i], min(a[i], mn), max(a[i], mx))
    return count

n, l, r, x = tuple(map(int, input().split()))
a = list(map(int, input().split()))
curr = []
start, sm, mn, mx = 0, 0, 100000000000000, -1
print(dfs(a, curr, start, sm, mn, mx))
