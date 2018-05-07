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
    if (ans.size() == n)
        return true;
    for (int i = 0; i < g[s].size(); i++)
        if (!vis[g[s][i]] && dfs(g[s][i]))
            return true;
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
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n && list[i] * 3LL >= list[j]; j++)
            if (list[i] * 2LL == list[j])
                g[i].push_back(j);
            else if (list[i] * 3LL == list[j])
                g[j].push_back(i);
            
    for (int i = 0; i < n; i++)
        if (dfs(i))
            break;
    for (int i = 0; i < ans.size(); i++)
        cout << list[ans[i]] << (i == (n - 1) ? '\n' : ' ');
    return 0;
}