#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#define MAXN 1000
using namespace std;

vector<int> g[MAXN];
int from[MAXN], ans;
int n, m;
bool use[MAXN];

bool Match(int x)
{
    for (int i = 0; i < g[x].size(); i++)
        if (!use[g[x][i]])
        {
            use[g[x][i]] = true;
            if (from[g[x][i]] == -1 || Match(from[g[x][i]]))
            {
                from[g[x][i]] = x;
                return true;
            }
        }
    return false;
}

int Hungary()
{
    ans = 0;
    memset(from, 255, sizeof(from));
    for (int i = 1; i <= n; i++)
    {
        memset(use, 0, sizeof(use));
        if (Match(i))
            ans++;
    }
    return ans;
}

int main()
{
    int tema, temb;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &tema, &temb);
            g[tema].push_back(temb);
        }
        printf("%d\n", Hungary());
    }
    return 0;
}