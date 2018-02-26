#include <algorithm>
#include <cstdio>
#include <iostream>
#define MAXN 10001
#define INF 0x3f3f3f3f
using namespace std;
struct EDGE
{
    int a, b, w;
};
int n, m;
int dis[MAXN];
EDGE g[MAXN];
bool BellmanFord()
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dis[g[j].b] = min(dis[g[j].b], dis[g[j].a] + g[j].w);
    for (int i = 0; i < m; i++)
        if (dis[g[i].b] > dis[g[i].a] + g[i].w)
            return false;
    return true;
}
int main()
{
    char tem[15];
    int ans = -INF;
    while (~scanf("%d", &n))
    {
        m = 0;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j < i; j++)
            {
                scanf("%s", tem);
                g[m + 1].b = g[m].a = i;
                g[m + 1].a = g[m].b = j;
                if (tem[0] != 'x')
                    g[m + 1].w = g[m].w = atoi(tem);
                else
                    g[m + 1].w = g[m].w = INF;
                m += 2;
            }
        BellmanFord();
        for (int i = 2; i <= n; i++)
            ans = max(ans, dis[i]);
        printf("%d\n", ans);
    }
    return 0;
}