import sys
n, k = tuple(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))
ingsd = {}
for i in range(n):
    ingsd[b[i] // a[i] + 1] = tuple(map(sum, zip(ingsd.get(b[i] // a[i] + 1, (0, 0)), (a[i] - b[i] % a[i], a[i]))))
ings = sorted(ingsd.items())
# # print(ings)
# curr = 0
# running = 0
# last_i = 0
# for i, (rem, req) in ings:
#     # print(i, rem, req, curr, running, last_i)
#     if curr + rem + running * (i - last_i) > k:
#         extra = (k - curr) // running if running != 0 else 0
#         print(extra + last_i)
#         sys.exit()
#     curr += rem
#     curr += running * (i - last_i)
#     running += req
#     last_i = i
# # no more other ingredients
# extra = (k - curr) // running if running != 0 else 0
# print(extra + last_i)

# binary search
lo, hi = 0, 2000000000
while lo < hi:
    mid = (lo + hi) // 2 + (lo + hi) % 2
    cost = 0
    for amt, (rem, req) in ings:
        if amt > mid: # have enough ingredients for sure
            break
        cost += rem + req * (mid - amt)
        if cost > k:
            break
    # print(mid, cost, k)
    if cost > k:
        hi = mid - 1
    else:
        lo = mid
print(lo)