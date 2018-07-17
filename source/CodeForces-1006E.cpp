#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> g[200001];
int a, b, cnt = 0, ans[200001], s[200001], e[200001];
void dfs(int n)
{
    cnt++;
    s[n] = cnt;
    ans[cnt] = n;
    for (int i = 0; i < g[n].size(); i++)
        dfs(g[n][i]);
    e[n] = cnt;
}
int main()
{
    int n, q, tem;
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        scanf("%d", &tem);
        g[tem].push_back(i);
    }
    dfs(1);
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &a, &b);
        if (b > e[a] - s[a] + 1)
            puts("-1");
        else
            printf("%d\n", ans[s[a] + b - 1]);
    }
    return 0;
}
