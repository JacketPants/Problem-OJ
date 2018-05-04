import math
a, b, c = map(int, input().strip().split())
s = math.sqrt(a * b * c)
print(int(s/a*4+s/b*4+s/c*4))
