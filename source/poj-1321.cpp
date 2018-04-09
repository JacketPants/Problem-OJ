#include <cstring>
#include <iostream>
using namespace std;
char p[10][10];
int n, m;
bool Check(int a, int b)
{
    for (int i = 1; i <= n; i++)
        if (p[a][i] == '*')
            return false;
    for (int i = 1; i <= n; i++)
        if (p[i][b] == '*')
            return false;
    return true;
}
int dfs(int x)
{
    if (x == m)
        return 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[i][j] == '#' && Check(i, j))
            {
                p[i][j] = '*';
                ans += dfs(x + 1);
                p[i][j] = '#';
            }
        }
    }
    return ans;
}
int main()
{
    while (~scanf("%d%d", &n, &m) && n != -1 && m != -1)
    {
        memset(p, '.', sizeof p);
        for (int i = 1; i <= n; i++)
        {
            getchar();
            for (int j = 1; j <= n; j++)
                p[i][j] = getchar();
        }
        printf("%d\n", dfs(0));
    }
    return 0;
}