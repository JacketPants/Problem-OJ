#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#define INF64 0x3f3f3f3f3f3f3f3f
#define P pair<int, int>
using namespace std;
map<int, vector<P>> mp;
int dis(P a, P b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
bool cmp(P a, P b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}
int main()
{
    int n, last = 0, now = 0;
    P tmp, lastl, lastr, nowl, nowr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &tmp.first, &tmp.second);
        mp[max(tmp.first, tmp.second)].emplace_back(tmp);
    }
    mp[0].emplace_back(P(0, 0));
    for (auto &it : mp)
        sort(it.second.begin(), it.second.end(), cmp);
    vector<vector<long long>> dp(int(mp.size()) + 1, vector<long long>(2, INF64));
    dp[0][0] = dp[0][1] = 0;
    for (auto &it : mp)
    {
        now++;
        nowl = it.second[0];
        nowr = it.second.back();
        lastl = mp[last][0];
        lastr = mp[last].back();
        dp[now][0] = min(dp[now][0], dp[now - 1][0] + dis(lastl, nowr) + dis(nowl, nowr));
        dp[now][0] = min(dp[now][0], dp[now - 1][1] + dis(lastr, nowr) + dis(nowl, nowr));
        dp[now][1] = min(dp[now][1], dp[now - 1][0] + dis(lastl, nowl) + dis(nowl, nowr));
        dp[now][1] = min(dp[now][1], dp[now - 1][1] + dis(lastr, nowl) + dis(nowl, nowr));
        last = it.first;
    }
    cout << min(dp[now][0], dp[now][1]);
    return 0;
}
