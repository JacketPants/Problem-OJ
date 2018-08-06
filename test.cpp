#include <algorithm>
#include <cstring>
#include <iostream>
#define INF 0x3f3f3f3f
using namespace std;

int ans, sum;
int grid[20][20];
bool vis[20];

bool Check()
{
    for (int i = 0; i < 16; i++)
    {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j < 16; j++)
        {
            if (vis[grid[i][j]])
                return false;
            vis[grid[i][j]] = true;
        }
    }
    for (int i = 0; i < 16; i++)
    {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j < 16; j++)
        {
            if (vis[grid[j][i]])
                return false;
            vis[grid[j][i]] = true;
        }
    }
    return true;
}

bool Check(int a)
{
    int x = a * 4;
    for (int i = 0; i < 4; i++)
    {
        memset(vis, 0, sizeof vis);
        for (int j = 0; j < 16; j++)
        {
            if (vis[grid[x + i][j]])
                return false;
            vis[grid[x + i][j]] = true;
        }
    }
    // for (int i = 0; i < 16; i++)
    // {
    //     memset(vis, 0, sizeof vis);
    //     for (int j = 0; j < 16; j++)
    //     {
    //         if (vis[grid[j][i]])
    //             return false;
    //         vis[grid[j][i]] = true;
    //     }
    // }
    return true;
}

void Trun(int a, int b)
{
    int x = a * 4;
    int y = b * 4;

    // swap(grid[x][y], grid[x + 3][y]);
    // swap(grid[x][y], grid[x + 3][y + 3]);
    // swap(grid[x][y], grid[x][y + 3]);

    // swap(grid[x + 1][y + 1], grid[x + 2][y + 1]);
    // swap(grid[x + 1][y + 1], grid[x + 2][y + 2]);
    // swap(grid[x + 1][y + 1], grid[x + 1][y + 2]);

    // swap(grid[x][y + 1], grid[x + 2][y]);
    // swap(grid[x][y + 1], grid[x + 3][y + 2]);
    // swap(grid[x][y + 1], grid[x + 1][y + 3]);

    // swap(grid[x + 1][y], grid[x + 3][y + 1]);
    // swap(grid[x + 1][y], grid[x + 2][y + 3]);
    // swap(grid[x + 1][y], grid[x][y + 2]);

    swap(grid[x][y], grid[x][y + 3]);
    swap(grid[x][y], grid[x + 3][y + 3]);
    swap(grid[x][y], grid[x + 3][y]);

    swap(grid[x + 1][y + 1], grid[x + 1][y + 2]);
    swap(grid[x + 1][y + 1], grid[x + 2][y + 2]);
    swap(grid[x + 1][y + 1], grid[x + 2][y + 1]);

    swap(grid[x][y + 1], grid[x + 1][y + 3]);
    swap(grid[x][y + 1], grid[x + 3][y + 2]);
    swap(grid[x][y + 1], grid[x + 2][y]);

    swap(grid[x + 1][y], grid[x][y + 2]);
    swap(grid[x + 1][y], grid[x + 2][y + 3]);
    swap(grid[x + 1][y], grid[x + 3][y + 1]);

    return;
}

void dfs(int x)
{
    // cout << x << endl;
    if (x == 4 && Check())
    {
        ans = min(ans, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                for (int l = 0; l < 4; l++)
                {
                    // printf("%d %d %d %d\n", i, j, k, l);
                    sum += i + j + k + l;
                    if (Check(x))
                        dfs(x + 1);
                    sum -= i + j + k + l;
                    Trun(x, 3);
                }
                Trun(x, 2);
            }
            Trun(x, 1);
        }
        Trun(x, 0);
    }
    return;
}

int main()
{
    FILE *fp = fopen("out", "w");
    int t;
    char ch;
    cin >> t;
    while (t--)
    {
        ans = INF;
        sum = 0;
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
        // cout << Check() << endl;
        dfs(0);
        // fprintf(fp, "%d\n", ans);
        printf("%d\n", ans);
    }
    fclose(fp);
    return 0;
}
/*
0123456789ABCDEF
123456789ABCDEF0
23456789ABCDEF01
3456789ABCDEF012
456789ABCDEF0123
56789ABCDEF01234
6789ABCDEF012345
789ABCDEF0123456
89ABCDEF01234567
9ABCDEF012345678
ABCDEF0123456789
BCDEF0123456789A
CDEF0123456789AB
DEF0123456789ABC
EF0123456789ABCD
F0123456789ABCDE

DC0342B1843CC3A1
694AFC63A5677DF6
E2750879F1B2289B
BF18DEA50ED9405E
A7C47AFC9B4F8F9A
39DFD48EE8C5C346
02E8165363A2E01B
61B52B09D1075D72
FA7947C672FA2D6C
153B2BEFE40C71E0
6C4891A5596D358A
D02E3D8083B149FB
E4281F835F7C8E06
F7CDCAD419EA9C42
A1B0027B0D86D5FA
5369695EB2347B31


681D5A0C9FDBB2F7
0A734B62E167D9E5
5C9B73EF3C208410
F24ED18948A5CA63
39FAED5616400B74
D120C4B7CA3DEF38
7EC829A085BE6D51
B56438F129F79C2A
5C7FBC4E3D08719F
AE8B1673BF42A58D
60D3AF25619C30BE
294190D8EA57264C
C7D1B35606835EAB
AF52A1E019BE4306
8B36DC78D425F7C9
E409492FC7FA18D2
*/