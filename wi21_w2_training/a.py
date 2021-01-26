import heapq
import sys
n, m = tuple(map(int, input().split()))
a = list(map(int, input().split()))
counts = {}
for p in a:
    counts[p] = counts.get(p, 0) + 1
heap = []
# print(counts)
for p, c in counts.items():
    heapq.heappush(heap, (-c, p))
orig = heap.copy()
for d in range(1, m // n + 2):
    for i in range(n):
        c, p = heapq.heappop(heap)
        # print(d, -c, p)
        if d <= -c:
            heapq.heappush(heap, (-(-c - d), p))
        else: # out of food
            print(d-1)
            sys.exit()
    heap = orig.copy()
print(0)
