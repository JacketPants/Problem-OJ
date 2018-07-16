#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
vector<int> g[200001];
int a, b, c, ans;
void dfs(int n)
{
    c++;
    if (c == b)
        ans = n;
    for (int i = 0; i < g[n].size(); i++)
        if (c != b)
            dfs(g[n][i]);
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
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &a, &b);
        c = 0;
        ans=-1;
        dfs(a);
        printf("%d\n", ans);
    }
    return 0;
}
