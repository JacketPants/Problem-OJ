#include <cmath>
#include <cstdio>
#define N 1e-10
int main()
{
    int t, x, a, y, b;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &x, &a, &y, &b);
        if (fabs(x - pow(y, b * 1.0 / a)) < N)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
