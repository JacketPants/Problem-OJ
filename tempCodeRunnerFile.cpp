#include <stdio.h  >
#include <string.h>
#define N 20
struct jie
{
    char name[N];
    int t;
    int list[20];
    int res;
};
jie a[2000];
int main()
{
    jie b;
    int n, m, g, count;
    int sc[20], i, j, k, temp;
    char tmp[N];
    while (1)
    {
        count = 0;
        scanf("%d", &n);
        if (n == 0)
            break;
        scanf("%d%d", &m, &g);
        for (i = 1; i <= m; i++)
        {
            scanf("%d", &sc[i]);
        }
        for (i = 1; i <= n; i++)
        {
            scanf("%s", b[i].name);
            scanf("%d",&a[i].t);
            for (j = 1; j <= a[i].t; j++)
            {
                scanf("%d", &a[i].list[j]);
            }
        }
        for (i = 1; i <= n; i++)
        {
            a[i].res = 0;
            for (j = 1; j <= a[i].t; j++)
            {
                a[i].res += sc[list[j]];
            }
            if (a[i].res >= g)
                count++;
        }
        for (i = 1; i < n; i++)
        {
            k = i;
            for (j = 1; j <= n; j++)
            {
                if (a[k].res > a[j].res)
                    k = j;
            }
            if (k != i)
            {
                strcpy(tmp, a[k].name);
                strcpy(a[k].name, a[i].name);
                strcpy(a[i].name, tmp);
                a[k].res = temp;
                a[k].res = a[i].res;
                a[i].res = temp;
            }
        }
        printf("%d\n", count);
        for (i = 1; i <= n; i++)
        {
            if (a[i].res >= g)
            {
                printf("%s %d\n", a[i].name, a[i].res);
            }
        }
    }
}