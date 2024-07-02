#include <cstdio>
#include <cstring>
#include <iostream>
#define lowbit(x) x & -x
#define MAXN 100010
int n;
long long treeA[MAXN], treeB[MAXN];
inline void add(long long *Tree, int x, int value)
{
    while (x <= n)
    {
        Tree[x] += value;
        x += lowbit(x);
    }
}

inline long long get(long long *Tree, int x)
{
    long long sum = 0;
    while (x)
    {
        sum += Tree[x];
        x -= lowbit(x);
    }
    return sum;
}

void add(long long *Treea, long long *Treeb, int a, int b, int value)
{
    add(Treea, a, (-value) * (a - 1));
    add(Treeb, a, value);
    add(Treea, b + 1, value * b);
    add(Treeb, b + 1, -value);
}

long long get(long long *Treea, long long *Treeb, int a, int b)
{
    return (get(Treea, b) + get(Treeb, b) * b) - (get(Treea, a - 1) + get(Treeb, a - 1) * (a - 1));
}

int main()
{
    int q, tem, a, b, c;
    long long ans;
    char op[10];
    while (~scanf("%d%d", &n, &q))
    {
        memset(treeA, 0, sizeof treeA);
        memset(treeB, 0, sizeof treeB);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &tem);
            add(treeA, i, tem);
        }
        for (int i = 0; i < q; i++)
        {
            scanf("%s%d%d", op, &a, &b);
            if (op[0] == 'C')
            {
                scanf("%d", &c);
                add(treeA, treeB, a, b, c);
            }
            else
            {
                printf("%lld\n", get(treeA, treeB, a, b));
            }
        }
    }
    return 0;
}
