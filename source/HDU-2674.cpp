#include <iostream>
int main()
{
    int n;
    long long ans;
    while (~scanf("%d", &n))
    {
        if (n > 40)
            ans = 0;
        else
        {
            ans = 1;
            for (int i = 2; i <= n; i++)
                ans = (ans * i) % 2009;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
