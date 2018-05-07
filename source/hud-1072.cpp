#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> list;
int p[10][10];
int g[10][10];
int pos[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void Search(int x)
{
    pair<int, int> tem;
    bool vis[10][10] = {false};
    queue<pair<int, int>> q;
    q.push(list[x]);
    while (!q.empty())
    {
        tem = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if (!vis[tem.first + pos[i][0]][tem.second + pos[i][0]]&&)
        }
    }
}
int main()
{
    int t, n, m;
    cin >> t;
    while (t--)
    {
        memset(p, 0, sizeof p);
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> p[i][j];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (p[i][j] == 2)
                    list.push_back(pair<int, int>(i, j));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (p[i][j] == 4)
                    list.push_back(pair<int, int>(i, j));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (p[i][j] == 3)
                    list.push_back(pair<int, int>(i, j));
    }
    return 0;
}