#include <cstring>
#include <iostream>
#define MAXN 1000010

int Tree[MAXN];
inline int lowbit(int x)
{
    return (x & -x);
}

void add(int x, int value)
{
    for (int i = x; i <= MAXN; i += lowbit(i))
        Tree[i] += value;
}

int get(int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += Tree[i];
    return sum;
}

int main()
{
    int t, n, tem, a, b;
    char order[10];
    std::cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {
        printf("Case %d:\n", tt);
        memset(Tree, 0, sizeof Tree);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &tem);
            add(i, tem);
        }
        while (scanf("%s", order) && *order != 'E')
        {
            if (*order == 'Q')
            {
                scanf("%d%d", &a, &b);
                printf("%d\n", get(b) - get(a - 1));
            }
            else if (*order == 'A')
            {
                scanf("%d%d", &a, &b);
                add(a, b);
            }
            else if (*order == 'S')
            {
                scanf("%d%d", &a, &b);
                add(a, -b);
            }
        }
    }
    return 0;
}
