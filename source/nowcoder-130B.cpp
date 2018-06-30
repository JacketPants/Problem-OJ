#include <cstring>
#include <iostream>

using namespace std;
int dp[501][501];
int p[501][501];
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &p[i][j]);
        dp[n][m] = p[n][m];
        for (int i = n; i; i--)
            for (int j = m; j; j--)
            {
                if (i == n && j == m)
                    continue;
                dp[i][j] = p[i][j];
                if (i == n)
                    dp[i][j] -= dp[i][j + 1];
                else if (j == m)
                    dp[i][j] -= dp[i + 1][j];
                else
                    dp[i][j] -= dp[i + 1][j] > dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];
            }
        cout << dp[1][1] << '\n';
    }
    return 0;
}