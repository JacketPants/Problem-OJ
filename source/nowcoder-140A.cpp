#include <iostream>
#define MOD 1000000007
#define N 100000
using namespace std;
int p[N + 1];
int dp[N + 1][2];
int main()
{
    int q, k, l, r;
    while (~scanf("%d%d", &q, &k))
    {
        for (int i = 0; i < k; i++)
        {
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        for (int i = k; i <= N; i++)
        {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = dp[i - k][0];
        }
        for (int i = 1; i <= N; i++)
            dp[i][0] = (dp[i][0] + dp[i][1]) % MOD + dp[i - 1][0]) % MOD;
        while (q--)
        {
            scanf("%d%d", &l, &r);
            printf("%d\n", (dp[r][0] + MOD - dp[l - 1][0]) % MOD);
        }
    }
    return 0;
}