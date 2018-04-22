#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int p[2000][2000];
int dp[2000][2000];
void Rotation(int x, int y, int l)
{
    int t;
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l; j++)
        {
            t = p[x + i][y + j];
            p[x + i][y + j] = p[x + l + i][y + j];
            p[x + l + i][y + j] = p[x + l + i][y + l + j];
            p[x + l + i][y + l + j] = p[x + i][y + l + j];
            p[x + i][y + l + j] = t;
        }
    }
}
int main()
{
    int n, m, x, y, l;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &p[i][j]);
    for (int j = 0; j < m; j++)
    {
        scanf("%d%d%d", &x, &y, &l);
        Rotation(x, y, l);
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = p[i][j] + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    printf("%d\n", dp[n][n]);
    return 0;
}