import sys
s = input()
if len(s) < 4:
    print('NO')
    sys.exit()

ab, ba = False, False
i = 0
while i < len(s) - 1:
    if s[i:i+2] == 'AB' and not ab:
        ab = True
        i += 1
    elif ab and s[i:i+2] == 'BA' and not ba:
        ba = True
        i += 1
    i += 1
    if ab and ba:
        print('YES')
        sys.exit()

ab, ba = False, False
i = 0
while i < len(s) - 1:
    if s[i:i+2] == 'BA' and not ba:
        ba = True
        i += 1
    elif ba and s[i:i+2] == 'AB' and not ab:
        ab = True
        i += 1
    i += 1
    if ab and ba:
        print('YES')
        sys.exit()

print('NO')
sys.exit()