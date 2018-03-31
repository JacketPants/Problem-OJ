#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int t, n, v;
    int p[1010], w[1010], dp[1010];
    scanf("%d", &t);
    while (t--)
    {
        memset(dp, 0, sizeof dp);
        scanf("%d%d", &n, &v);
        for (int i = 1; i <= n; i++)
            scanf("%d", p + i);
        for (int i = 1; i <= n; i++)
            scanf("%d", w + i);
        for (int i = 1; i <= n; i++)
            for (int j = v; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + p[i]);
        printf("%d\n", dp[v]);
    }
    return 0;
}