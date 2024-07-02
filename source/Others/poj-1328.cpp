#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
struct Island
{
    double s, e;//题目中对于坐标是非离散的
}list[1005];
bool cmp(const Island &a, const Island &b)
{
    return a.e < b.e;
}
int main()
{
    int n, d, x, y, ans, t = 0;
    double tem;
    while (~scanf("%d%d",&n,&d) && (n || d))
    {
        bool isCan = d > 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d",&x,&y);
            if(!((tem = sqrt(d * d - y * y))>=0))//在sqrt中，不可以用判负当作不成立
                isCan = false;
            list[i].s = x - tem;
            list[i].e = x + tem;
        }
        if (isCan)
        {
            sort(list, list + n, cmp);
            ans = 1;
            tem = list->e;
            for (int i = 1; i < n; i++)
                if (list[i].s > tem)
                {
                    ans++;
                    tem = list[i].e;
                }
        }
        else
            ans = -1;
        printf("Case %d: %d\n", ++t, ans);
    }
    return 0;
}