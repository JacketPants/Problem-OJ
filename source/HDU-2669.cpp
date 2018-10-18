#include <iostream>
long long extend_gcd(long long a, long long b, long long &x, long long &y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    long long a, b, x, y;
    while (~scanf("%lld%lld", &a, &b))
        if (extend_gcd(a, b, x, y) == 1)
        {
            while (x <= 0)
            {
                x += b;
                y -= a;
            }
            printf("%lld %lld\n", x, y);
        }
        else
            puts("sorry");
    return 0;
}
