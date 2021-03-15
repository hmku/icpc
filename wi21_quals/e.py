import sys
n = input()
a = list(input().split())

def poss(a1, a2):
    if len(a1) < len(a2):
        return (None, None)
    if len(a2) == 1 and int(a1) > 0:
        return (0, '0')
    if int(a1) > int('1' + a2[1:]):
        return (0, '1'+a2[1:])
    for i in range(1, len(a2)):
        if int(a1) > int(a2[:i]+'0'+a2[i+1:]):
            return (0, a2[:i]+'0'+a2[i+1:])
    for i in range(0, len(a1)):
        if int(a2) < int(a1[:i]+'9'+a1[i+1:]):
            return (-1, a1[:i]+'9'+a1[i+1:])
    return (None, None)

for i in range(1, len(a)):
    j, s = poss(a[i-1], a[i])
    if s is not None:
        a[i+j] = s
        print(' '.join(a))
        sys.exit()

print('impossible')