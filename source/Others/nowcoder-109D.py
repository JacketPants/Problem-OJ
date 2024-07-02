import math
r = 6371009.0
t = map(int, input().strip().split())
for i in t:
    a, b, c, d = map(float, input().strip().split())
    z1 = r * math.sin(b)
    tem1 = r * math.cos(b)
    y1 = tem1 * math.sin(a)
    x1 = tem1 * math.cos(a)
    z2 = r * math.sin(d)
    tem2 = r * math.cos(d)
    y2 = tem2 * math.sin(c)
    x2 = tem2 * math.cos(c)
    print(int(math.sqrt((x1-x2)**2+(y1-y2)**2+(z1-z2)**2)))
