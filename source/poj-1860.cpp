#include <algorithm>
#include <cstdio>
#include <iostream>
#define MAXN 10001
#define INF 0x3f3f3f3f
using namespace std;
struct EDGE
{
    int a, b;
    double r, p;
};
int n, m, s;
double v;
double dis[MAXN];
EDGE g[MAXN];
void Init_dis()
{
    for (int i = 1; i <= n; i++)
        dis[i] = 0;
}
bool BellmanFord()
{
    dis[s] = v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dis[g[j].b] = max(dis[g[j].b], (dis[g[j].a] - g[j].p) * g[j].r);
    for (int i = 0; i < m; i++)
        if (dis[g[i].b] < (dis[g[i].a] - g[i].p) * g[i].r)
            return true;
    return false;
}
int main()
{
    int tema, temb;
    while (~scanf("%d%d%d%lf",&n,&m,&s,&v))
    {
        m *= 2;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &tema, &temb);
            scanf("%lf%lf", &g[i].r, &g[i].p);
            g[i].a = tema;
            g[i].b = temb;
            i++;
            scanf("%lf%lf", &g[i].r, &g[i].p);
            g[i].a = temb;
            g[i].b = tema;
        }
        Init_dis();
        if (BellmanFord())
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}