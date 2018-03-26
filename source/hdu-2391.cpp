#include <cstring>
#include <iostream>
using namespace std;
int p[1000][1000];
int dp[1000];
int main()
{
    int t, n, m;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        memset(p, 0, sizeof p);
        memset(dp, 0, sizeof dp);
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                scanf("%d", &p[i][j]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!i)
                    dp[j] = dp[j - 1] + p[i][j];
                else if (!j)
                    dp[j] = dp[j] + p[i][j];
                else
                    dp[j] = p[i][j] + max(dp[j], dp[j - 1]);
        printf("Scenario #%d:\n", k);
        printf("%d\n\n", dp[m - 1]);
    }
    return 0;
}