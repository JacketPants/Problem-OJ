#include <iostream>
#include <vector>
#define MAXN 200010
using namespace std;
bool vis[MAXN];
long long cnt[MAXN];
vector<int> p[MAXN];
void Search(int n)
{
    long long ans = 1LL;
    vis[n] = true;
    for (int i = 0; i < p[n].size(); i++)
    {
        if (vis[p[n][i]])
            continue;
        Search(p[n][i]);
        ans *= cnt[p[n][i]] + 1LL;
        ans %= 10000007LL;
    }
    cnt[n] = ans;
}
int main()
{
    int n, a, b;
    long long ans = 0;
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        p[a].push_back(b);
        p[b].push_back(a);
    }
    Search(1);
    for (int i = 1; i <= n; i++)
        ans = (ans + cnt[i]) % 10000007LL;
    printf("%lld\n", ans);
    return 0;
}