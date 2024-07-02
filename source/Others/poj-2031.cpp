#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define MAXN 20000
#define INF 0x3f3f3f3f
#define INF_8 0x3f
using namespace std;
struct EDGE
{
    int a, b;
    double l;
};
struct Station
{
    double x, y, z, r;
};
EDGE e[MAXN];
Station list[MAXN];
int n, m;
double Prim()
{
    bool arr[MAXN]={false};
    double dis[MAXN], ans = 0;
    int mark;
    for (int i = 0; i < n;i++)
        dis[i] = INF;
    dis[0] = 0;
    for (int i = 0; i < n; i++)
    {
        mark = -1;
        for (int j = 0; j < n; j++)
            if (!arr[j] && (dis[j] < dis[mark] || mark == -1))
                mark = j;
        if (mark == -1)
            break;
        arr[mark] = true;
        ans += dis[mark];
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
    int tem;
    double l;
    while (~scanf("%d", &n) && n)
    {
        m = n * (n - 1) / 2;
        tem = 0;
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf", &list[i].x, &list[i].y, &list[i].z, &list[i].r);
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; tem++, j++)
            {
                e[tem].a = i;
                e[tem].b = j;
                l = sqrt(pow(list[i].x - list[j].x, 2) + pow(list[i].y - list[j].y, 2) + pow(list[i].z - list[j].z, 2)) - (list[i].r + list[j].r);
                e[tem].l = l > 0 ? l : 0;
            }
        printf("%.3f\n", Prim());
    }
    return 0;
}