#include <cstring>
#include <iostream>

using namespace std;
char p[1002][1002];
int dp[1002][1002];
int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main()
{
    int t, n, m, ansa, ansb;
    cin >> t;
    while (t--)
    {
        ansa = ansb = 0;
        memset(p, 0, sizeof p);
        memset(dp, 0, sizeof dp);
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            getchar();
            for (int j = 1; j <= m; j++)
                p[i][j] = getchar();
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (p[i][j] == 'i')
                    for (int k = 0; k < 4; k++)
                        if (p[i + pos[k][0]][j + pos[k][1]] == 'g')
                            dp[i][j]++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (p[i][j] == 'r')
                    for (int k = 0; k < 4; k++)
                        if (p[i + pos[k][0]][j + pos[k][1]] == 'i')
                            dp[i][j] += dp[i + pos[k][0]][j + pos[k][1]];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (p[i][j] == 'l')
                    for (int k = 0; k < 4; k++)
                        if (p[i + pos[k][0]][j + pos[k][1]] == 'r')
                            ansa += dp[i + pos[k][0]][j + pos[k][1]];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (p[i][j] == 'a')
                    for (int k = 0; k < 4; k++)
                        if (p[i + pos[k][0]][j + pos[k][1]] == 'c')
                            dp[i][j]++;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (p[i][j] == 't')
                    for (int k = 0; k < 4; k++)
                        if (p[i + pos[k][0]][j + pos[k][1]] == 'a')
                            ansb += dp[i + pos[k][0]][j + pos[k][1]];
        printf("%d %d\n", ansa, ansb);
    }
    return 0;
}