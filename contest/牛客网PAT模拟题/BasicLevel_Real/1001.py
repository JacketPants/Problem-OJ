T = int(input())
for t in range(1, T+1):
    a, b, c = map(int, input().strip().split())
    print('Case #%d: %s' % (t, 'true' if a+b > c else 'false'))
