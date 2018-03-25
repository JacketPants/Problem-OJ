#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    long long k, n, ans, p;
    // char anstr[10000] = {0};
    while (~scanf("%d", &k))
    {
        p = ans = 0;
        n = k * 2;
        for (long long i = k + 1; i <= k * 2; i++)
            if ((i * k) % (i - k) == 0)
                ans++;
        printf("%lld\n", ans);
    }
    return 0;
}