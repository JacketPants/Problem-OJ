#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
int nxt[21][3] = {0}, cnt, n;
bool vis[21];
vector<int> ans;
void dfs(int now)
{
    if (ans.size() == 20)
    {
        if (now == n)
        {
        	ans.push_back(now);
            printf("%d: ", ++cnt);
            for (int th : ans)
            {
                printf(" %d", th);
            }
            puts("");
            ans.pop_back();
        }
        return;
    }
    if (vis[now])
        return;
    ans.push_back(now);
    vis[now] = true;
    for (int i = 0; i < 3; i++)
    {
        dfs(nxt[now][i]);
    }
    vis[now] = false;
    ans.pop_back();
    return;
}
int main()
{
    for (int i = 1; i <= 20; i++)
        scanf("%d%d%d", &nxt[i][0], &nxt[i][1], &nxt[i][2]);
    while (~scanf("%d", &n) && n)
    {
        cnt = 0;
        memset(vis, 0, sizeof vis);
        dfs(n);
    }
    return 0;
}
