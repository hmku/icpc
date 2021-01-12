n = int(input())
a = sorted([int(val) for val in input().split()])
cs = 0
count = 0
for i in range(len(a)):
    if a[i] >= cs:
        cs += a[i]
        count += 1
print(count)