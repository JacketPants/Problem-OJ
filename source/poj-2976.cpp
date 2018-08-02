#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const double esp = 1e-4;
const int maxn = 1010;
int n, k;
struct node
{
    double a, b, d;
} q[maxn];
int cmp(struct node x, struct node y)
{
    return x.d < y.d;
}
double Dinkelbach()
{
    double L, ans = 0;
    double x, y;
    while (1)
    {
        L = ans;
        for (int i = 0; i < n; i++)
            q[i].d = q[i].a - L * q[i].b;
        sort(q, q + n, cmp);
        x = y = 0;
        for (int i = k; i < n; i++)
        {
            x += q[i].a;
            y += q[i].b;
        }
        ans = x / y;
        if (fabs(L - ans) < esp)
            return L;
    }
}
int main()
{
    while (~scanf("%d %d", &n, &k))
    {
        if (!n && !k)
            break;
        for (int i = 0; i < n; i++)
            scanf("%lf", &q[i].a);
        for (int i = 0; i < n; i++)
            scanf("%lf", &q[i].b);
        printf("%.0f\n", Dinkelbach() * 100);
    }
    return 0;
}