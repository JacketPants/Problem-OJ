#include <iostream>
#include <map>
#include <string>
#define MAXN 30
#define INF 0x3f3f
#define INF_8 0x3f
using namespace std;
int g[MAXN][MAXN], pre[MAXN];
int n;
void Init_g()
{
    for (int i = 1; i <= n; i++)
    {
        g[i][i] = 1;
        for (int j = i + 1; j <= n; j++)
            g[i][j] = g[j][i] = 0;
    }
}
void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] = g[i][j] || (g[i][k] && g[k][j]); // min(g[i][j], g[i][k] + g[k][j]);
}
int main()
{
    int m, p, t = 1;
    bool isArr[MAXN];
    string a, b;
    map<string, int> list;
    map<int, string> relist;
    while (~scanf("%d%d", &n, &m) && n && m)
    {
        printf("Calling circles for data set %d:\n", t++);
        for (int i = 0; i <= n; i++)
            isArr[i] = false;
        list.clear();
        Init_g();
        p = 1;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            if (!list[a])
            {
                relist[p] = a;
                list[a] = p++;
            }
            if (!list[b])
            {
                relist[p] = b;
                list[b] = p++;
            }
            g[list[a]][list[b]] = 1;
        }
        Floyd();
        for (int i = 1; i <= n; i++)
            if (!isArr[i])
            {
                p = 0;
                for (int j = 1; j <= n; j++)
                    if (!isArr[j] && g[i][j] && g[j][i])
                    {
                        isArr[j] = true;
                        if (p)
                            printf(", ");
                        cout << relist[j];
                        p++;
                    }
                putchar('\n');
            }
    }
    return 0;
}