#include <algorithm>
#include <iostream>
using namespace std;

int dp[2000005];
int list[2000][2];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        scanf("%d%d", &list[i][0], &list[i][1]);
    for (int i = 0; i < m; i++)
    {
        for (int j = n; j >= list[i][0]; j--)
        {
            dp[j] = max(dp[j], dp[j - list[i][0]] + list[i][1]);
        }
    }
    cout << dp[n] << endl;
    return 0;
}