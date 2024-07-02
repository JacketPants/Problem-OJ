#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
int list[101], dp[101], fa[101];
stack<int> ans;
int main()
{
    int n, len;
    while (cin >> n && n)
    {
        len = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", list + i);
            dp[i] = 1;
            fa[i] = -1;
            for (int j = 1; j <= i; j++)
                if (list[j] < list[i] && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    fa[i] = j;
                }
            len = len < dp[i] ? dp[i] : len;
        }
        for (int i = 1; i <= n; i++)
            if (dp[i] == len)
            {
                while (i > 0)
                {
                    ans.push(i);
                    i = fa[i];
                }
                break;
            }
        printf("The number is %d:", len);
        while (!ans.empty())
        {
            printf(" %d", ans.top());
            ans.pop();
        }
        putchar('\n');
    }
    return 0;
}

/*
#include <algorithm>
#include <iostream>
using namespace std;
int list[101], dp[101], s[101], ans[101];
int main()
{
    int n, len, k;
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", list + i);
        len = 1;
        ans[1] = s[1] = list[1];
        for (int i = 1; i <= n; i++)
        {
            if (s[len] < list[i])
                k = ++len;
            else
                k = lower_bound(s + 1, s + len + 1, list[i]) - s;
            s[k] = list[i];
            ans[k] = i;
        }
        printf("The number is %d:", len);
        for (int i = 1; i <= len; i++)
            printf(" %d", ans[i]);
        putchar('\n');
    }
    return 0;
}
*/