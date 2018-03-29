#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int list[50001];
int dp[50001];
int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; i++)
            scanf("%d", list + i);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j < i; j++)
                if (list[j] < list[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
        printf("%d\n", *max_element(dp + 1, dp + n + 1) + 1);
    }
    return 0;
}