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
    bool arr[MAXN]={0};
    int dis[MAXN], ans = 0, mark;
    memset(dis, INF_8, sizeof(dis));
    dis[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        mark = -1;
        for (int j = 1; j <= n; j++)
            if (!arr[j] && dis[j] < INF && (dis[j] < dis[mark] || mark == -1))
                mark = j;
        if (mark == -1)
            return -INF;
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
    int ans;
    while (cin >> m >> n, m)
    {
        for (int i = 0; i < m; i++)
            scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].l);
        ans = Prim();
        if (ans < 0)
            cout << '?' << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
/*
10 6
1 2 6
1 3 1
1 4 5
2 5 3
2 3 5
5 3 6
5 6 6
3 6 4
3 4 5
6 4 2
3 3
1 2 1
1 3 2
2 3 4
1 3
2 3 2
0 100
*/