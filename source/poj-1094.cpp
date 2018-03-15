#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define MAXN 10000
using namespace std;
vector<int> g[MAXN];
int du[MAXN], L[MAXN];
int n, m;
int toposort()
{
    int cnt = 0, x, tem;
    memset(du, 0, sizeof(du));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < g[i].size(); j++)
            du[g[i][j]]++;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; i++)
        if (!du[i])
            q.push(i);
    while (!q.empty())
    {
        x = q.top();
        q.pop();
        L[cnt++] = x;
        for (int j = 0; j < g[x].size(); j++)
        {
            tem = g[x][j];
            du[tem]--;
            if (!du[tem])
                q.push(tem);
        }
    }
    return cnt;
    // if (cnt == n)
    //     return 1;
    // return 0;
}

int main()
{
    char str[5], ans;
    while (scanf("%d%d", &n, &m))
    {
        for (int i = 0; i < n; i++)
            g[i].clear();
        for (int i = 0; i < m; i++)
        {
            scanf("%s", str);
            g[str[0] - 'A'].push_back(str[2] - 'A');
        }
        ans = toposort();
    }
    return 0;
}