#include <algorithm>
#include <iostream>
using namespace std;
char a[100005], ans[100005];
int main()
{
    int t, n;
    bool flag;
    cin >> t;
    while (t--)
    {
        flag = false;
        scanf("%d%s%s", &n, a, ans);
        for (int i = 0; i < n; i++)
        {
            if (a[i] < ans[i])
            {
                flag = true;
                break;
            }
        }
        if (flag)
            puts("-1");
        else
            puts(ans);
    }
    return 0;
}
