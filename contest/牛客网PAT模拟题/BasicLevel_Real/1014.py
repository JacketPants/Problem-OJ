n, m = input().split('E')

m = int(m)

ans = ""
if m < 0:
    n = n.replace('.', '')
    if n[0] == '-':
        ans += n[0]
    ans += "0."
    for i in range(1, abs(m)):
        ans += '0'
    for i in range(1, len(n)):
        ans += n[i]
elif m > 0:
    n = n.replace('.', '')
    if n[0] == '-':
        ans += n[0]
    for i in range(1, max(len(n), m + 2)):
        if i == m + 2:
            ans+='.'
        if i < len(n):
            ans += n[i]
        else:
            ans += '0'
else:
    ans = str(n)
print(ans)
# -1.23400E-03
# +1.123E+2
# -1.123E+2
# +1.123E+10