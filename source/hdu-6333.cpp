#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int ans[4][4];
int grid[20][20];
bool vis[16];

bool Check(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j < 16; j++)
        {
            if (vis[grid[x * 4 + i][j]])
                return false;
            else
                vis[grid[x * 4 + i][j]] = true;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j < 16; j++)
        {
            if (vis[grid[j][y * 4 + i]])
                return false;
            else
                vis[grid[j][y * 4 + i]] = true;
        }
    }
    return true;
}

void Trun(int a, int b);
{
    int x = a * 4;
    int y = b * 4;

    swap(grid[x][y], grid[x + 3][y]);
    swap(grid[x][y], grid)

}

void dfs(int x, int y)
{
    for (int i = 1; i <= 4; i++)
    {
        Turn(x, y);
    }
}

int main()
{
    int t;
    char ch;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 16; i++)
        {
            getchar();
            for (int j = 0; j < 16; j++)
            {
                ch = getchar();
                if (ch >= 'A' && ch <= 'F')
                    grid[i][j] = ch - 'A' + 10;
                else
                    grid[i][j] = ch - '0';
            }
        }
        printf("%d\n", dfs(0, 0));
    }
    return 0;
}