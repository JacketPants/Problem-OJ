num = list(map(int, input().strip().split()))
ans = ""
for i in range(1, len(num)):
    if num[i] != 0:
        ans += str(i)
        num[i] -= 1
        break
for i in range(len(num)):
    ans += str(i) * num[i]
print(ans)
