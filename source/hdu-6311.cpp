// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #include <vector>
// #define MAXN 100010
// #define MAXM 500050
// using namespace std;

// struct Edge
// {
//     int to, next;
//     int index;
//     int dir;
//     bool flag;
// };
// Edge edge[MAXM];
// int head[MAXN], fa[MAXN], du[MAXN], sum, tot;
// vector<int> ans[MAXN], sp[MAXN], stk, tem;
// void init(int n)
// {
//     memset(head, -1, sizeof head);
//     memset(edge, 0, sizeof edge);
//     sum = tot = 0;
//     for (int i = 0; i <= n; i++)
//     {
//         ans[i].clear();
//         sp[i].clear();
//         fa[i] = i;
//     }
// }
// int getfa(int u)
// {
//     return u == fa[u] ? u : fa[u] = getfa(fa[u]);
// }

// void addedge(int u, int v, int index)
// {
//     edge[tot].to = v;
//     edge[tot].next = head[u];
//     edge[tot].index = index;
//     edge[tot].dir = 0;
//     edge[tot].flag = false;
//     head[u] = tot++;
//     edge[tot].to = u;
//     edge[tot].next = head[v];
//     edge[tot].index = index;
//     edge[tot].dir = 1;
//     edge[tot].flag = false;
//     head[v] = tot++;
// }
// void dfs(int u)
// {
//     for (int i = head[u]; i != -1; i = edge[i].next)
//         if (!edge[i].flag)
//         {
//             edge[i].flag = true;
//             edge[i ^ 1].flag = true;
//             dfs(edge[i].to);
//             stk.push_back(i);
//             //            ans[sum].push_back(i);
//         }
// }
// int main()
// {
//     // freopen("1003.in", "r", stdin);
//     // freopen("out", "w", stdout);

//     int n, m;
//     while (cin >> n >> m)
//     {
//         init(n);
//         int u, v;
//         memset(du, 0, sizeof(du));
//         for (int i = 1; i <= m; i++)
//         {
//             scanf("%d%d", &u, &v);
//             addedge(u, v, i);
//             du[u]++;
//             du[v]++;
//             fa[getfa(u)] = getfa(v);
//         }

//         for (int i = 1; i <= n; i++)
//             if (du[i] & 1)
//                 sp[getfa(i)].push_back(i);

//         for (int i = 1; i <= n; i++)
//         {
//             if (fa[i] == i)
//             {
//                 if (!sp[i].size())
//                 {
//                     stk.clear();
//                     dfs(i);
//                     while (stk.size())
//                         ans[sum].push_back(stk.back());
//                     sum++;
//                 }
//                 else
//                 {
//                     for (int j = 0; j < sp[i].size(); j += 2)
//                         addedge(sp[i][j], sp[i][j + 1], 0);
//                     dfs(i);
//                     // tem = ans[sum];
//                     // ans[sum].clear();
//                     tem.clear();
//                     for (int i = stk.size() - 1; i >= 0; i--)
//                         if (!edge[stk[i]].index)
//                             tem.push_back(i);

//                     for (int i = 0; i < tem.size() - 1; i++)
//                     {
//                         for (int j = tem[i] - 1; j > tem[i + 1]; j--)
//                             ans[sum].push_back(stk[j]);
//                         sum++;
//                     }

//                     for (int j = pos[pos.size() - 1] - 1; j; j--)
//                         ans[sum].push_back(stk[j]);
//                     for (int j = top; j > pos[0]; j--)
//                         ans[sum].push_back(stk[j]);

//                     sum++;

//                     // int p = tem.size() - 1;
//                     // while (edge[tem[p--]].index)
//                     //     ;
//                     // for (int j = p; j >= 0; j--)
//                     // {
//                     //     if (edge[tem[j]].index)
//                     //         ans[sum].push_back(tem[j]);
//                     //     else
//                     //     {
//                     //         // if (ans[sum].size())
//                     //         sum++;
//                     //     }
//                     // }
//                     // for (int j = tem.size() - 1; j > p + 1; j--)
//                     //     ans[sum].push_back(tem[j]);
//                     // // if (ans[sum].size())
//                     // sum++;
//                 }
//             }
//         }
//         int anssum = sum;
//         for (int i = 0; i < sum; i++)
//             if (!ans[i].size())
//                 anssum--;

//         printf("%d\n", anssum);

//         for (int i = 0; i < sum; i++)
//         {
//             if (ans[i].size())
//             {
//                 printf("%d", ans[i].size());
//                 for (int j = 0; j < ans[i].size(); j++)
//                 {
//                     putchar(' ');
//                     if (edge[ans[i][j]].dir)
//                         putchar('-');
//                     printf("%d", edge[ans[i][j]].index);
//                 }
//                 putchar('\n');
//             }
//         }
//     }
//     return 0;
// }

#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>
using namespace std;

#define next VIVONEX
#define clr(_) memset(_, 0, sizeof(_))

const int N = 100005, M = 500005;

int n, m, G[N], tot, e[M], next[M], deg[N], top, stk[M], vis[M], fa[N], sum;
vector<int> ji[N], ans[N];

int getfa(int u)
{
    return u == fa[u] ? u : fa[u] = getfa(fa[u]);
}

inline void adde(int u, int v)
{
    //    cout<<u<<" "<<v<<endl;
    next[++tot] = G[u];
    G[u] = tot;
    e[tot] = v;
}

void dfs(int u)
{
    for (int &v = G[u]; v; v = next[v])
    {
        if (vis[v >> 1])
            continue;
        int t = v;
        vis[v >> 1] = 1;
        dfs(e[v]);
        stk[++top] = (t & 1 ? -(t >> 1) : t >> 1);
    }
}

void init()
{
    clr(G);
    clr(deg);
    clr(vis);
    tot = 1;
    for (int i = 1; i <= n; i++)
        ji[i].clear(), ans[i].clear(), fa[i] = i;
}

void solve()
{
    init();
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        adde(u, v);
        adde(v, u);
        deg[u]++;
        deg[v]++;
        fa[getfa(u)] = getfa(v);
    }
    for (int i = 1; i <= n; i++)
        if (deg[i] & 1)
            ji[getfa(i)].push_back(i);
    sum = 0;
    for (int i = 1; i <= n; i++)
        if (fa[i] == i)
        {
            if (!ji[i].size())
            {
                top = 0;
                dfs(i);
                sum++;
                while (top)
                    ans[sum].push_back(stk[top--]);
            }
            else
            {
                for (int j = 0; j < ji[i].size(); j += 2)
                    adde(ji[i][j], ji[i][j + 1]), adde(ji[i][j + 1], ji[i][j]);
                top = 0;
                dfs(i);
                vector<int> pos;
                for (int i = top; i; i--)
                    if (stk[i] > m || stk[i] < -m)
                        pos.push_back(i);
                for (int i = 0; i < pos.size() - 1; i++)
                {
                    sum++;
                    for (int j = pos[i] - 1; j > pos[i + 1]; j--)
                        ans[sum].push_back(stk[j]);
                }
                sum++;
                for (int j = pos[pos.size() - 1] - 1; j; j--)
                    ans[sum].push_back(stk[j]);
                for (int j = top; j > pos[0]; j--)
                    ans[sum].push_back(stk[j]);
            }
        }
    int t = sum;
    for (int i = 1; i <= sum; i++)
        if (ans[i].size() == 0)
            t--;
    cout << t << endl;
    for (int i = 1; i <= sum; i++)
        if (ans[i].size() != 0)
        {
            printf("%d", ans[i].size());
            for (int j = 0; j < ans[i].size(); j++)
                printf(" %d", ans[i][j]);
            puts("");
        }
}

int main()
{
    while (cin >> n >> m)
        solve();
    return 0;
}