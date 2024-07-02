#include <cstdio>
#include <cstdlib>
#include <iostream>
#define MAXN 101
#define INF 0x3f3f3f3f
#define INF_8 0x3f
using namespace std;
int g[MAXN][MAXN];
int n;
void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}
int main()
{
    char tem[15];
    int ans = -INF;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
            g[i][i] = 0;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < i; j++)
            {
                scanf("%s", tem);
                if (tem[0] != 'x')
                    g[i][j] = g[j][i] = atoi(tem);
                else
                    g[i][j] = g[j][i] = INF;
            }
        Floyd();
        for (int i = 2; i <= n; i++)
            ans = max(ans, g[1][i]);
        printf("%d\n", ans);
    }
    return 0;
}