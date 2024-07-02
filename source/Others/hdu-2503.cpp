#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}
int main()
{
    int t, a, b, c, d, e, f, gcd;
    cin >> t;
    while (t--)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        e = a * d + b * c;
        f = b * d;
        gcd = GCD(max(e, f), min(e, f));
        printf("%d %d\n", e / gcd, f / gcd);
    }
    return 0;
}