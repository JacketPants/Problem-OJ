#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int n;
long long list[100];
vector<int> g[100];
vector<int> ans;
bool vis[100] = {false};
bool dfs(int s)
{
    ans.push_back(s);
    vis[s] = true;
    // cout << ans.size();
    if (ans.size() == n)
        return true;
    for (int i = 0; i < g[s].size(); i++)
    {
        if (!vis[g[s][i]])
        {
            if (dfs(g[s][i]))
                return true;
        }
    }
    vis[s] = false;
    ans.pop_back();
    return false;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", list + i);
    sort(list, list + n);
    // for (int i = 0; i < n; i++)
        // cout << list[i] << endl;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if (list[i] * 2LL == list[j])
            {
                // cout << list[i] << ' ' << list[j] << endl;
                g[i].push_back(j);
            }
            else if (list[i] * 3LL == list[j])
            {
                // cout << list[i] << ' ' << list[j] << endl;
                g[j].push_back(i);
            }
        }
    // for (int i = 0; i < n; i++)
    // {
        // cout << '!';
        // cout << i << ':';
        // for (int j = 0; j < g[i].size(); j++)
            // cout << g[i][j] << ' ';
        // cout << '\n';
    // }
    for (int i = 0; i < n; i++)
    {
        if (dfs(i))
            break;
        // cout << ans.size() << endl;
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            putchar(' ');
        cout << list[ans[i]];
    }
    putchar('\n');
    return 0;
}