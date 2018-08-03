#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1995;
const int maxm = 1000000;

int father[maxn];
vector<pair<int, int> > adj[maxn];
bool vis[maxm];

int getFather(int x)
{
    return x == father[x] ? x : father[x] = getFather(father[x]);
}

void add(int x, int y, int z)
{
    adj[x].push_back(make_pair(z, y));
    adj[y].push_back(make_pair(z, x));
}

vector<int> path;

#define eid first
#define vtx second

void dfs(int u)
{
    for (int it = 0; it < adj[u].size(); it++)
    {
        if (!vis[adj[u][it].eid])
        {
            vis[adj[u][it].eid] = true;
            dfs(adj[u][it].vtx);
            path.push_back(adj[u][it].eid);
        }
    }
}

#undef eid
#undef vtx

bool solve()
{
    for (int i = 0; i < maxn; i++)
        father[i] = i;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < adj[i].size(); j++)
            father[getFather(i)] = getFather(adj[i][j].second);
    int origin = -1;
    for (int i = 0; i < maxn; i++)
    {
        if (adj[i].size())
        {
            if (adj[i].size() % 2 == 1)
                return false;
            if (origin == -1)
                origin = i;
            if (getFather(i) != getFather(origin))
                return false;
            sort(adj[i].begin(), adj[i].end());
        }
    }
    path.clear();
    memset(vis, 0, sizeof(vis));
    if (origin != -1)
        dfs(origin);
    reverse(path.begin(), path.end());

    return true;
}

int main()
{
    int x, y, z;
    while (~scanf("%d%d", &x, &y) && (x || y))
    {
        for (int i = 0; i < maxn; i++)
            adj[i].clear();
        scanf("%d", &z);
        add(x, y, z);
        while (~scanf("%d%d", &x, &y) && (x || y))
        {
            scanf("%d", &z);
            add(x, y, z);
        }
        if (solve())
        {
            for (int i = 0; i < path.size(); i++)
                printf("%d ", path[i]);
            putchar('\n');
        }
        else
        {
            puts("Round trip does not exist.");
        }
    }
    return 0;
}