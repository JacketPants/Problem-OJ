#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
using namespace std;
struct Water
{
    int a, b;
    Water()
    {
        a = 0;
        b = 0;
    }
};
int n, x, y;
Water list[10000];
map<long long, Water> before;
long long bin[35] = {1, 2, 4, 8, 16,
                     32, 64, 128, 256, 512,
                     1024, 2048, 4096, 8192, 16384,
                     32768, 65536, 131072, 262144, 524288,
                     1048576, 2097152, 4194304, 8388608, 16777216,
                     33554432, 67108864, 134217728, 268435456, 536870912,
                     1073741824, 2147483648, 4294967296, 8589934592, 17179869184};

int GCD(int x, int y)
{
    int z = y;
    while (x % y != 0)
    {
        z = x % y;
        x = y;
        y = z;
    }
    return z;
}
bool Check(long long n)
{
    long long g;
    Water m;
    for (int i = 0; n; n /= 2, i++)
    {
        if (n % 2)
        {
            m.a += list[i].a;
            m.b += list[i].b;
        }
    }
    g = GCD(m.a, m.b);
    m.a /= g;
    m.b /= g;
    return m.a == x && m.b == y;
}
int main()
{
    int t;
    long long ans;
    long long m;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d%d%d", &n, &x, &y);
        m = pow(2, n);
        for (int i = 0; i < n; i++)
            scanf("%d%d", &list[i].a, &list[i].b);
        for (long long i = 1; i < m; i++)
            ans += Check(i);
        printf("%lld\n", ans);
    }
    return 0;
}