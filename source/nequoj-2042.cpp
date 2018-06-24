#include <iostream>

using namespace std;

int main()
{
    int n, ans = 0, cnt = 0;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i <= n; i++)
    {
        if (getchar() == '6')
        {
            cnt++;
        }
        else
        {
            if (cnt >= 3)
            {
                ans += cnt - 2;
            }
            cnt = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}