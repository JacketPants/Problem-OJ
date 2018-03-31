#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int pos[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<int> g[500];
int from[500], n;
bool use[500];
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
    int ans = 0;
    memset(from, 255, sizeof from);
    for (int i = 1; i < n; i++)
    {
        memset(use, 0, sizeof use);
        if (Match(i))
            ans++;
    }
    return ans;
}
int main()
{
    int t, x, y, p[50][50];
    scanf("%d", &t);
    while (t--)
    {
        n = 1;
        memset(p, 0, sizeof p);
        scanf("%d%d", &y, &x);
        getchar();
        for (int i = 1; i <= y; i++)
        {
            for (int j = 1; j <= x; j++)
                if (getchar() == '*')
                    p[i][j] = n++;
            getchar();
        }
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i <= y; i++)
            for (int j = 1; j <= x; j++)
                if (p[i][j])
                    for (int k = 0; k < 4; k++)
                        if (p[i + pos[k][0]][j + pos[k][1]])
                            g[p[i][j]].push_back(p[i + pos[k][0]][j + pos[k][1]]);
        printf("%d\n", (n - 1) - Hungary() / 2);
    }
    return 0;
}