import sys
n = input()

# 1 digit
for i in range(len(n)):
    if n[i] == '0' or n[i] == '8':
        print('YES')
        print(n[i])
        sys.exit()

# 2 digit
for i in range(len(n)):
    for j in range(i+1, len(n)):
        if int(n[i] + n[j]) % 8 == 0:
            if n[i] != '0':
                print('YES')
                print(n[i] + n[j])
                sys.exit()
# 3 digit
for i in range(len(n)):
    for j in range(i+1, len(n)):
        for k in range(j+1, len(n)):
            if int(n[i] + n[j] + n[k]) % 8 == 0:
                if n[i] != '0':
                    print('YES')
                    print(n[i] + n[j] + n[k])
                    sys.exit()
print('NO')
sys.exit()