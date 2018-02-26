#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#define MAXN 10001
#define INF 0x3f3f3f3f
using namespace std;
struct EDGE
{
    string a, b;
    double r;
};
int n, m;
map<string, double> dis;
EDGE g[MAXN];
bool BellmanFord()
{
    dis.begin()->second = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            dis[g[j].b] = max(dis[g[j].b], dis[g[j].a] * g[j].r);
    for (int i = 0; i < m; i++)
        if (dis[g[i].b] < dis[g[i].a] * g[i].r)
            return true;
    return false;
}
int main()
{
    string str;
    int t = 1;
    while (~scanf("%d",&n) && n)
    {
        dis.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> str;
            dis[str] = 0;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
            cin >> g[i].a >> g[i].r >> g[i].b;
        if (BellmanFord())
            printf("Case %d: Yes\n", t);
        else
            printf("Case %d: No\n", t);
        t++;
    }
    return 0;
}