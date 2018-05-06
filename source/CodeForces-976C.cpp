#include <algorithm>
#include <iostream>

using namespace std;

struct P
{
    int a, b, x;
} list[300000];
bool cmp(P a, P b)
{
    if (a.a == b.a)
        return a.b > b.b;
    return a.a < b.a;
}

int main()
{
    int n, max = 0;
    bool find = false;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &(list[i].a), &(list[i].b));
        list[i].x = i + 1;
    }
    sort(list, list + n, cmp);
    for (int i = 1; i < n; i++)
    {
        if (list[i].a >= list[max].a && list[i].b <= list[max].b)
        {
            printf("%d %d\n", list[i].x, list[max].x);
            find = true;
            break;
        }
        if (list[i].b > list[max].b)
            max = i;
    }
    if (!find)
        printf("-1 -1\n");
    return 0;
}