#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

struct Step
{
    int x, y, n;
    bool operator<(const Step &a) const
    {
        return this->n > a.n;
    }
    Step(int x, int y, int n)
    {
        this->x = x;
        this->y = y;
        this->n = n;
    }
    Step() {}
};
char p[302][302];
vector<Step> tp[302][302];
int mp[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int vis[302][302];
int main()
{
    int n, m, t, a, b, c, d, e, f, x, y;
    bool isFind;
    Step ans, tem;
    while (~scanf("%d%d%d", &n, &m, &t))
    {
        isFind = false;
        priority_queue<Step> q;
        memset(p, '#', sizeof p);
        memset(vis, 0x3f, sizeof vis);
        for (int i = 0; i < 302; i++)
            for (int j = 0; j < 302; j++)
                tp[i][j].clear();
        for (int i = 1; i <= n; i++)
        {
            getchar();
            for (int j = 1; j <= m; j++)
            {
                p[i][j] = getchar();
                if (p[i][j] == 'S')
                {
                    a = i;
                    b = j;
                }
            }
        }
        for (int i = 0; i < t; i++)
        {
            scanf("%d%d%d%d", &c, &d, &e, &f);
            if (p[c + 1][d + 1] != '#' && p[e + 1][f + 1] != '#')
                tp[c + 1][d + 1].push_back(Step(e + 1, f + 1, 0));
        }
        q.push(Step(a, b, 0));
        vis[a][b] = 0;
        while (!q.empty())
        {
            ans = q.top();
            q.pop();
            x = ans.x;
            y = ans.y;
            if (p[x][y] == 'T')
            {
                isFind = true;
                break;
            }
            for (int i = 0; i < tp[x][y].size(); i++)
                if (ans.n + 3 < vis[tp[x][y][i].x][tp[x][y][i].y])
                {
                    tem = tp[x][y][i];
                    tem.n = ans.n + 3;
                    vis[tem.x][tem.y] = tem.n;
                    q.push(tem);
                }
            for (int i = 0; i < 4; i++)
                if (ans.n + 1 < vis[x + mp[i][0]][y + mp[i][1]] && p[x + mp[i][0]][y + mp[i][1]] != '#')
                {
                    tem.x = x + mp[i][0];
                    tem.y = y + mp[i][1];
                    tem.n = ans.n + 1;
                    vis[tem.x][tem.y] = tem.n;
                    q.push(tem);
                }
        }
        if (isFind)
            printf("%d\n", ans.n);
        else
            puts("-1");
    }
    return 0;
}
/*
5 5 1
..S..
.....
.###.
.....
..T..
1 2 3 3
5 5 1
..S..
.....
.###.
.....
..T..
3 3 1 2
5 5 1
S.#..
..#..
###..
.....
....T
0 1 0 2
4 4 2
S#.T
.#.#
.#.#
.#.#
0 0 0 3
2 0 2 2
*/