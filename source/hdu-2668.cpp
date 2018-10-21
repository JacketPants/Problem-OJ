#include <cstring>
#include <iostream>
using namespace std;
int s[128];
char str[10000005];
int main()
{
    int n, ans, ansl, l, tmp;
    while (~scanf("%d", &n))
    {
        scanf("%s", str);
        memset(s, -1, sizeof s);
        ans = ansl = l = tmp = 0;
        for (int i = 0; i <= n; i++)
        {
            if (i == n || s[str[i]] >= l)
            {
                if (tmp > ans)
                {
                    ans = tmp;
                    ansl = l;
                }
                l = s[str[i]] + 1;
                tmp = i - s[str[i]];
            }
            else
                tmp++;
            s[str[i]] = i;
        }
        printf("%d %d %d\n", ans, ansl, ansl + ans - 1);
    }
    return 0;
}
