#include <iostream>
#include <random>
#include <vector>
using namespace std;
vector<int> ran;
vector<int> p[1000002];
vector<long long> f[1000002];
int main()
{
    int n, m, t, tem, x1, x2, y1, y2, k;
    long long ans = 0;
    srand('!');
    for (int i = 1000001; i >= 0; i--)
        ran.push_back(rand() % 10010000 + 1000001);
    scanf("%d%d%d", &n, &m, &t);
    for (int i = 0; i <= n + 1; i++)
        for (int j = 0; j <= m + 1; j++)
        {
            p[i].push_back(0);
            f[i].push_back(0);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &tem);
            p[i][j] = ran[tem];
        }
    for (int i = 0; i < t; i++)
    {
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
        f[x1][y1] += ran[k];
        f[x1][y2 + 1] -= ran[k];
        f[x2 + 1][y1] -= ran[k];
        f[x2 + 1][y2 + 1] += ran[k];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            if (f[i][j] % p[i][j])
                ans++;
        }
    printf("%lld\n", ans);
    return 0;
}