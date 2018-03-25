t = int(input())
l = list()
l.append(1)
l.append(1)
for i in range(0, 40):
    l.append(sum(l))
while(t > 0):
    t -= 1
    n = int(input())
    print(l[n])
    