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
    bool arr[MAXN] = {false};
    int ans = 0, mark = 0;
    int dis[MAXN] = {0};
    for (int i = 0; i < n; i++)
        dis[i] = INF;
    dis[0] = 0;
    for (int i = 0; i < n; i++)
    {
        mark = -1;
        for (int j = 0; j < n; j++)
            if (!arr[j] && (dis[j] < dis[mark] || mark == -1))
                mark = j;
        if(mark==-1)//不成立的判定条件
            break;
        arr[mark] = true;
        ans = ans < dis[mark] ? dis[mark] : ans;
        for (int j = 0; j < n; j++)
            if (g[mark][j] && g[mark][j] < dis[j])
                dis[j] = g[mark][j];
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &g[i][j]);
        printf("%d\n", Prim());
    }
    return 0;
}
