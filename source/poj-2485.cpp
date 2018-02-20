#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

#define MAXN 1000
#define INF 0x3f3f3f3f
using namespace std;
int g[MAXN][MAXN]; //邻接矩阵
int n, m;          //点和边
int Prim()
{
    int ans = 0, mark = 0;
    int dis[MAXN] = {0};
    for (int i = 0; i < n; i++)
        dis[i] = INF;
    bool isArr[MAXN] = {false};
    isArr[0] = true;
    dis[0] = 0;
    for (int i = 0; i < n; i++)
        if (g[0][i] && g[0][i] < dis[i])
            dis[i] = g[0][i];
    //测试代码

    // for (int k = 0; k < n; k++)
    //     cout << dis[k] << '\t';
    // cout << endl;
    for (int i = 1; i < n; i++)
    {
        mark = 0;
        for (int j = 0; j < n; j++)
            if (dis[j] && (dis[j] < dis[mark] || !mark))
                mark = j;
        isArr[mark] = true;
        ans = max(ans, dis[mark]);
        for (int j = 0; j < n; j++)
            if (g[mark][j] && g[mark][j] < dis[j])
                dis[j] = g[mark][j];
        dis[mark] = 0;
        //测试代码

        // for (int k = 0; k < n; k++)
        //     cout << dis[k] << '\t';
        // cout << endl;
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(g, 0, sizeof(g));
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &g[i][j]);
        printf("%d\n", Prim());
    }
    return 0;
}
/*
6 10
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
*/
/*答案是15*/
