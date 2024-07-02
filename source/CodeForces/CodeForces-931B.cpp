#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int ans, n, a, b;
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        ans = 0;
        while (a != b)
        {
            a = ceil(a / 2.0);
            b = ceil(b / 2.0);
            ans++;
        }
        if (ans == ceil(log(n)/log(2)))
            puts("Final!");
        else
            printf("%d\n", ans);
    }
    return 0;
}