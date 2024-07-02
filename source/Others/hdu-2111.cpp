#include <algorithm>
#include <iostream>
using namespace std;
struct S
{
    double p, m;
};
bool cmp(S a, S b)
{
    return a.p >= b.p;
}
int main()
{
    int v, n;
    double ans;
    S list[105];
    while (~scanf("%d", &v) && v)
    {
        scanf("%d", &n);
        ans = 0;
        for (int i = 0; i < n; i++)
            scanf("%lf%lf", &list[i].p, &list[i].m);
        sort(list, list + n, cmp);
        for (int i = 0; v && i < n; i++)
        {
            if (v < list[i].m)
            {
                ans += list[i].p * v;
                v = 0;
            }
            else
            {
                ans += list[i].p * list[i].m;
                v -= list[i].m;
            }
        }
        printf("%.0lf\n", ans);
    }
    return 0;
}