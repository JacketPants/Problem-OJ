#include <cstdio>
int main()
{
    long long f[100], n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i < 100; i++)
        f[i] = f[i - 1] + f[i - 2];
    while (~scanf("%lld", &n))
        printf("%lld\n", f[n]);
    return 0;
}