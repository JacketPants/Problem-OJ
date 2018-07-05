#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    long long v[1005], w[1005];
    long long dp[1005];
    long long V, N;
    while (cin >> V >> N)
    {
        memset(dp, 0, sizeof dp);
        for (long long i = 0; i < N; i++)
        {
            cin >> v[i] >> w[i];
        }
        for (long long i = 0; i < N; i++)
        {
            for (long long j = V; j >= v[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        sort(dp, dp + N);
        cout << dp[V] << endl;
    }
    return 0;
}