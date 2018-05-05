#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 21
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

long long g[N][N][N];
int x, y, z, n;

long long sum(int a, int b, int c, int d, int C)
{
    return g[b][d][C] - g[a - 1][d][C] - g[b][c - 1][C] + g[a - 1][c - 1][C];
}

int main()
{
    int tema, temb, temc, temd;
    memset(g, 0, sizeof(g));
    scanf("%d%d%d%d", &x, &y, &z, &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &tema, &temb, &temc, &temd);
        g[tema][temb][temc] = temd;
    }
    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= y; j++)
            for (int k = 1; k <= z; k++)
                g[i][j][k] += (g[i - 1][j][k] + g[i][j - 1][k] - g[i - 1][j - 1][k]);
    long long ans = -INF;
    for (int a = 1; a <= x; a++)
        for (int b = a; b <= x; b++)
            for (int c = 1; c <= y; c++)
                for (int d = c; d <= y; d++)
                {
                    int e = 1;
                    int f = 1;
                    long long m = 0;
                    while (f <= z)
                    {
                        m += sum(a, b, c, d, f);
                        if (m > ans)
                            ans = m;
                        while (m < 0 && e <= f)
                        {
                            m -= sum(a, b, c, d, e);
                            e++;
                            if (e <= f && m > ans)
                                ans = m;
                        }
                        f++;
                    }
                }
    printf("%lld\n", ans);
    return 0;
}