#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 10000
#define INF 0x3f3f3f3f
#define INF_8 0x3f
using namespace std;
struct EDGE
{
    int a, b, l;
};
EDGE e[MAXN];
int n, m;
int Prim()
{
    bool arr[MAXN];
    int dis[MAXN], ans = 0, mark;
    memset(dis, INF_8, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        mark = -1;
        for (int j = 1; j <= n; j++)
            if (!arr[j] && (dis[j] < dis[mark] || mark == -1))
                mark = j;
        if (mark == -1)
            return -INF;
        arr[mark] = true;
        ans = max(ans, dis[mark]);
        for (int j = 0; j < m; j++)
            if (arr[e[j].a] && !arr[e[j].b])
                dis[e[j].b] = min(dis[e[j].b], e[j].l);
            else if (!arr[e[j].a] && arr[e[j].b])
                dis[e[j].a] = min(dis[e[j].a], e[j].l);
    }
    return ans;
}
int main()
{
    while (~scanf("%d%d",&n,&m))
    {
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].l);
        printf("%d\n", Prim());
    }
    return 0;
}