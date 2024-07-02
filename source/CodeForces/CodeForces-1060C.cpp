#include <algorithm>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;
int a[2020], b[2020], suma[2020] = {0}, sumb[2020] = {0}, lena[2020], lenb[2020];
int main()
{
    int n, m, x, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= m; i++)
        scanf("%d", b + i);
    scanf("%d", &x);
    for (int i = 1; i <= n; i++)
        suma[i] = a[i] + suma[i - 1];
    for (int i = 1; i <= m; i++)
        sumb[i] = b[i] + sumb[i - 1];
    for (int i = 1; i <= n; i++)
    {
        lena[i] = INF;
        for (int j = 0; i + j <= n; j++)
            lena[i] = min(lena[i], suma[j + i] - suma[j]);
    }
    for (int i = 1; i <= m; i++)
    {
        lenb[i] = INF;
        for (int j = 0; i + j <= m; j++)
            lenb[i] = min(lenb[i], sumb[j + i] - sumb[j]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (i * j > ans && 1LL * lena[i] * lenb[j] <= x)
                ans = i * j;
        }
    cout << ans;
    return 0;
}
