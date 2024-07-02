#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int list[50010];
int eat[50010];
int Find(int x)
{
    while (list[x] != x)
        x = list[x];
    return x;
}
void Join(int n, int x)
{
    while (list[x] != x)
    {
        x = list[x];
        list[x] = n;
    }
}
int main()
{
    int n, k, d, x, y, ans, fax, fay;
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 1; i <= n; i++)
            eat[i] = list[i] = i;
        ans = 0;
        for (int i = 0; i < k; i++)
        {
            scanf("%d%d%d", &d, &x, &y);
            if (x > n || y > n)
            {
                ans++;
                continue;
            }
            fax = Find(x);
            fay = Find(y);
            // 合并
            if (d == 1)
            {
                
                if (fax != fay && (eat[fax] == fay || eat[fay] == fax))
                    ans++;
                else
                    Join(fax, y);
            }
            // 查询
            else
            {
                if (fax == fay || (eat[fax] == fay && eat[fay] == fax))
                    ans++;
                else
                    eat[fax] = fay;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}