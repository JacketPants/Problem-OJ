#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#define MAXN 10001
#define INF 0x3f3f3f3f
using namespace std;
// 求单源最短路径，时间复杂度为O(n *m)，时间复杂度高，最好换用SPFA方法
// dis数组是表示源点到i点的距离，算法执行完成后保存答案
// g为边的集合
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
    string tema, temb;
    while (~scanf("%d%d", &n, &m) && (n || m))
    {
        cin >> tema >> temb;
    }
    return 0;
}