#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int p[101][101];
int main()
{
    int t, n, ans, tema, temb, temc, temd;
    scanf("%d", &t);
    while (t--)
    {
        ans = 1;
        memset(p, 0, sizeof p);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d%d", &tema, &temb, &temc, &temd);
            for (int i = tema; i < temc; i++)
                for (int j = temb; j < temd; j++)
                    p[i][j]++;
        }
        for (int i = 1; i <= 100; i++)
            for (int j = 1; j <= 100; j++)
                ans = max(ans, p[i][j]);
        printf("%d\n", ans);
    }
    return 0;
}