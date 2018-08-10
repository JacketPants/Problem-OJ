// #include <cstdio>
// #include <cstring>
// #define lowbit(x) x & -x
// #define MAXN 1000010

// long long TreePoint[MAXN];
// long long TreeSum[MAXN];

// void add(long long *tp, long long *ts, int x, int value)
// {
//     long long value_n = (x - 1) * value;
//     for (int i = x; i <= MAXN; i += lowbit(i))
//     {
//         tp[i] += value;
//         ts[i] += value_n;
//     }
// }

// long long get(long long *t, int x)
// {
//     long long sum = 0;
//     for (int i = x; i; i -= lowbit(i))
//         sum += t[i];
//     return sum;
// }

// void add(long long *tp, long long *ts, int a, int b, int value)
// {
//     add(tp, ts, a, value);
//     add(tp, ts, b + 1, -value);
// }

// long long get(long long *tp, long long *ts, int a, int b)
// {
//     return (b * get(tp, b) - get(ts, b)) - ((a - 1) * get(tp, a - 1) - get(ts, a - 1));
// }

// int main()
// {
//     int n, q, tema, temb, a, b, c;
//     char ch[10];
//     while (~scanf("%d%d", &n, &q))
//     {
//         tema = temb = 0;
//         memset(TreePoint, 0, sizeof TreePoint);
//         memset(TreeSum, 0, sizeof TreeSum);
//         for (int i = 1; i <= n; i++)
//         {
//             scanf("%d", &tema);
//             add(TreePoint, TreeSum, i, tema - temb);
//             temb = tema;
//         }
//         for (int i = 0; i < q; i++)
//         {
//             scanf("%s%d%d", ch, &a, &b);
//             if (ch == 'Q')
//             {
//                 printf("%lld\n", get(TreePoint, TreeSum, a, b));
//             }
//             else
//             {
//                 scanf("%d", &c);
//                 add(TreePoint, TreeSum, a, b, c);
//             }
//         }
//     }
//     return 0;
// }

#include <cstdio>
#include <cstring>
#include <iostream>
#define lowbit(x) x & -x
#define MAXN 100010
int n;
long long treeA[MAXN], treeB[MAXN];
inline void add(long long *Tree, int x, int value)
{
    // for (int i = x; i <= n; i += lowbit(i))
    //     Tree[i] += value;
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
    // for (int i = x; i; i -= lowbit(i))
    //     sum += Tree[i];
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
