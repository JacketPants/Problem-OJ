#include <iostream>

using namespace std;
long long a[100001], ans;
int main()
{
    int t, n, s, sum;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        sum = ans = s = 0;
        a[n] = -1;
        for (int i = 0; i < n; i++)
            scanf("%lld", a + i);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] < a[i - 1])
            {
                if (a[s] != a[i - 1])
                {
                    sum++;
                    ans += a[i - 1] - a[s];
                }
                s = i;
            }
        }
        printf("%lld %d\n", ans, sum << 1);
    }
    return 0;
}