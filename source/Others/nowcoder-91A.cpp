#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main()
{
    int n, t;
    long long ans = 0;
    cin >> t;
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", a + i);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", b + i);
        for (int i = 1; i < n; i++)
        {
            if (a[i] > b[i])
            {
                ans += a[i] - b[i];
                a[i + 1] += a[i] - b[i];
            }
            else if (a[i] < b[i])
            {
                ans += b[i] - a[i];
                a[i + 1] -= b[i] - a[i];
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}