#include <algorithm>
#include <iostream>
using namespace std;
struct H
{
    int n, m, p;
} list[101];
bool cmp(H &a, H &b)
{
    if (a.p == b.p)
        return a.m < b.m;
    return a.p < b.p;
}
int main()
{
    int t, c, q, n;
    bool isSorry;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &c);
        for (int i = 0; i < c; i++)
            scanf("%d%d%d", &list[i].n, &list[i].m, &list[i].p);
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            isSorry = true;
            sort(list, list + c, cmp);
            scanf("%d", &n);
            for (int j = 0; j < c; j++)
            {
                if (list[j].m >= n)
                {
                    printf("%d\n", list[j].n);
                    list[j].m -= n;
                    isSorry = false;
                    break;
                }
            }
            if (isSorry)
                puts("sorry");
        }
    }
    return 0;
}