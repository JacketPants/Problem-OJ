#include <iostream>
using namespace std;
int main()
{
    int t, n, now, tem, a, b, sum, ans;
    cin >> t;
    for (int k = 1; k <= t; k++)
    {
        tem = sum = 0;
        ans = -0x3f3f;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &now);
            if (sum < 0)
            {
                sum = 0;
                tem = i;
            }
            sum += now;
            if (sum >= ans)
            {
                a = tem;
                b = i;
                ans = sum;
            }
        }
        printf("Case %d:\n%d %d %d\n", k, ans, a+1, b+1);
        if(k!=t)
            putchar('\n');
    }
    return 0;
}