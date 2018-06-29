#include <algorithm>
#include <iostream>
using namespace std;

long long Gcd(long long a, long long b)
{
    return b == 0 ? a : Gcd(b, a % b);
}

int main()
{
    int t;
    long long l[3], tem;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld", l, l + 1, l + 2);
        tem = Gcd(Gcd(l[0], l[1]), l[2]);
        printf("%lld\n", (*max_element(l, l + 3) / tem) - 3);
    }
    return 0;
}