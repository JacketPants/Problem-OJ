#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int k, n, ans, p;
    char anstr[10000] = {0};
    while (~scanf("%d", &k))
    {
        p = ans = 0;
        n = k * 2;
        for (int i = k + 1; i <= k * 2; i++)
        {
            if ((i * k) % (i - k) == 0)
            {
                ans++;
                p += sprintf(anstr + p, "1/%d = 1/%d + 1/%d\n", k, (i * k) / (i - k), i);
            }
        }
        printf("%d\n%s", ans, anstr);
    }
    return 0;
}