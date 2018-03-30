#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
vector<int> g[1001];
int from[1001], n;
bool use[1001];
bool Match(int x)
{
    for (int i = 0; i < g[x].size(); i++)
    {
        if (!use[g[x][i]])
        {
            use[g[x][i]] = true;
            if (from[g[x][i]] == -1 || Match(from[g[x][i]]))
            {
                from[g[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}
int Hungary()
{
    int ans = 0;
    memset(from, 255, sizeof from);
    for (int i = 1; i <= n; i++)
    {
        memset(use, 0, sizeof use);
        if (Match(i))
            ans++;
    }
    return ans;
}
int main()
{
    int k, x, y;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d", &x, &y);
            g[x].push_back(y);
        }
        printf("%d\n", Hungary());
    }
    return 0;
}