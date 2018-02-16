#include <algorithm>
#include <iostream>
using namespace std;
const long long INF = (1LL << 60) - 1;
int main()
{
    int m, n;
    long long listA[50], listB[50], tem, ans;
    while (~scanf("%d%d", &n, &m))
    {
        ans = INF;
        for (int i = 0; i < n; i++)
            scanf("%lld", listA + i);
        for (int i = 0; i < m; i++)
            scanf("%lld", listB + i);
        for (int i = 0; i < n; i++)
        {
            tem = -INF;
            for (int j = 0; j < n; j++)
                if (i != j)
                    for (int k = 0; k < m; k++)
                        tem = max(tem, listA[j] * listB[k]);
            ans = min(ans, tem);
        }
        printf("%lld\n", ans);
    }
    return 0;
}