#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
struct P
{
    int x, y, s, t;
    bool operator>(const P &x) const
    {
        return this->t > x.t;
    }
    P(int x = 1, int y = 1, int s = 6, int t = 0)
    {
        this->x = x;
        this->y = y;
        this->s = s;
        this->t = t;
    }
};

int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int g[10][10];
bool vis[10][10][8];

int main()
{
    int t, n, m, ans;
    P tem;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        memset(g, 0, sizeof g);
        memset(vis, 0, sizeof vis);
        priority_queue<P, vector<P>, greater<P>> q;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &g[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (g[i][j] == 2)
                {
                    vis[i][j][6] = true;
                    q.push(P(i, j));
                }
        while (!q.empty())
        {
            tem = q.top();
            q.pop();
            if (g[tem.x][tem.y] == 3)
            {
                ans = tem.t;
                break;
            }
            if (tem.s > 1)
                for (int i = 0; i < 4; i++)
                {
                    if (g[tem.x + pos[i][0]][tem.y + pos[i][1]] == 4 && !vis[tem.x + pos[i][0]][tem.y + pos[i][1]][6])
                    {
                        vis[tem.x + pos[i][0]][tem.y + pos[i][1]][6] = true;
                        q.push(P(tem.x + pos[i][0], tem.y + pos[i][1], 6, tem.t + 1));
                    }
                    else if (g[tem.x + pos[i][0]][tem.y + pos[i][1]] && !vis[tem.x + pos[i][0]][tem.y + pos[i][1]][tem.s - 1])
                    {
                        vis[tem.x + pos[i][0]][tem.y + pos[i][1]][tem.s - 1] = true;
                        q.push(P(tem.x + pos[i][0], tem.y + pos[i][1], tem.s - 1, tem.t + 1));
                    }
                }
        }
        if (ans)
            printf("%d\n", ans);
        else
            puts("-1");
    }
    return 0;
}