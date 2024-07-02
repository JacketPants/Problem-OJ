#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, k, l, b;
    while (~scanf("%d%d", &n, &k))
    {
        int dp[2000] = {0};
        vector<pair<int, int>> list(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &list[i].second);
        for (int i = 0; i < n; i++)
            scanf("%d", &list[i].first);
        sort(list.rbegin(), list.rend());
        for (int i = 0; i < n; i++)
            for (int j = k; j >= 1; j--)
                dp[j] = max(dp[j], dp[j - 1] + list[i].second - (j - 1) * list[i].first);
        printf("%d\n", dp[k]);
    }
    return 0;
}
