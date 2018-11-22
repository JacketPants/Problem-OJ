List = list(map(int, input().strip().split()))
flag = False
Is = [False, False, False, False, False]
ans = [0, 0, 0, [], 0]
for i in range(1, List[0] + 1):
    if (List[i] % 10 < 1):
        Is[0] = True
        ans[0] += List[i]
    if (List[i] % 5 == 1):
        Is[1] = True
        ans[1] += (-1)**int(flag) * List[i]
        flag = not flag
    if (List[i] % 5 == 2):
        Is[2] = True
        ans[2] += 1
    if (List[i] % 5 == 3):
        Is[3]= True
        ans[3].append(List[i])
    if (List[i] % 5 == 4):
        Is[4] = True
        ans[4]= max(ans[4], List[i])

print(ans[0] if Is[0] else 'N', ans[1] if Is[1] else 'N', ans[2] if Is[2] else 'N',
      ('%.1f' % (sum(ans[3])/len(ans[3]))) if Is[0] else 'N', ans[4] if Is[4] else 'N')
