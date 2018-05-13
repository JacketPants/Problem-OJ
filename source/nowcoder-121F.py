t = int(input())
for i in range(t):
    x, n, k = map(int, input().strip().split())
    tem = x ** n
    # print(tem)
    ans = 0
    while tem > 0:
        tem = tem // k
        ans = ans + 1
    print("Case ", i+1, ": ", ans, sep='')
