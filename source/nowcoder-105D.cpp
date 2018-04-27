#include <cstring>
#include <iostream>
using namespace std;
int fib[46];
bool b[46];
int main()
{
    long long ans, tem;
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 2;
    for (int i = 3; i < 45; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    int t, n, p;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0LL;
        tem = 1LL;
        memset(b, 0, sizeof b);
        scanf("%d", &n);
        for (p = 44; p && n; p--)
        {
            if (n >= fib[p])
            {
                n -= fib[p];
                b[p] = true;
            }
        }
        for (bool isChange = true; isChange;)
        {
            isChange = false;
            for (int i = 3; i < 45; i++)
                if (b[i] && !b[i - 1] && !b[i - 2])
                {
                    b[i] = false;
                    isChange = b[i - 1] = b[i - 2] = true;
                }
        }
        for (int i = 1; i < 45; i++)
        {
            if (b[i])
                ans += tem;
            tem *= 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}