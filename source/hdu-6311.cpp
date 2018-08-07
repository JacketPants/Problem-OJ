#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 100010
#define MAXM 500050
using namespace std;

struct Edge
{
    int to, next;
    int index;
    int dir;
    bool flag;
};
Edge edge[MAXM];
int head[MAXN], fa[MAXN], du[MAXN], sum, tot;
vector<int> ans[MAXN], sp[MAXN], tem;
void init(int n)
{
    memset(head, -1, sizeof head);
    memset(edge, 0, sizeof edge);
    sum = tot = 0;
    for (int i = 0; i <= n; i++)
    {
        ans[i].clear();
        sp[i].clear();
        fa[i] = i;
    }
}
int getfa(int u)
{
    return u == fa[u] ? u : fa[u] = getfa(fa[u]);
}

void addedge(int u, int v, int index)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].index = index;
    edge[tot].dir = 0;
    edge[tot].flag = false;
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].next = head[v];
    edge[tot].index = index;
    edge[tot].dir = 1;
    edge[tot].flag = false;
    head[v] = tot++;
}
void dfs(int u)
{
    for (int i = head[u]; i != -1; i = edge[i].next)
        if (!edge[i].flag)
        {
            edge[i].flag = true;
            edge[i ^ 1].flag = true;
            dfs(edge[i].to);
            ans[sum].push_back(i);
        }
}
int main()
{
    // freopen("1003.in", "r", stdin);
    // freopen("out", "w", stdout);

    int n, m;
    while (cin >> n >> m)
    {
        init(n);
        int u, v;
        memset(du, 0, sizeof(du));
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            addedge(u, v, i);
            du[u]++;
            du[v]++;
            fa[getfa(u)] = getfa(v);
        }

        for (int i = 1; i <= n; i++)
            if (du[i] & 1)
                sp[getfa(i)].push_back(i);

        for (int i = 1; i <= n; i++)
        {
            if (fa[i] == i)
            {
                if (!sp[i].size())
                {
                    dfs(i);
                    if (ans[sum].size())
                        sum++;
                }
                else
                {
                    for (int j = 0; j < sp[i].size(); j += 2)
                        addedge(sp[i][j], sp[i][j + 1], 0);
                    dfs(i);
                    tem = ans[sum];
                    ans[sum].clear();
                    int p = tem.size() - 1;
                    while (edge[tem[p--]].index)
                        ;
                    for (int j = p; j >= 0; j--)
                    {
                        if (edge[tem[j]].index)
                            ans[sum].push_back(tem[j]);
                        else
                        {
                            // if (ans[sum].size())
                            sum++;
                        }
                    }
                    for (int j = tem.size() - 1; j > p + 1; j--)
                        ans[sum].push_back(tem[j]);
                    // if (ans[sum].size())
                    sum++;
                }
            }
        }
        int anssum = sum;
        for (int i = 0; i < sum; i++)
            if (!ans[i].size())
                anssum--;

        printf("%d\n", anssum);

        for (int i = 0; i < sum; i++)
        {
            if (ans[i].size())
            {
                printf("%d", ans[i].size());
                for (int j = 0; j < ans[i].size(); j++)
                {
                    putchar(' ');
                    if (edge[ans[i][j]].dir)
                        putchar('-');
                    printf("%d", edge[ans[i][j]].index);
                }
                putchar('\n');
            }
        }
    }
    return 0;
}