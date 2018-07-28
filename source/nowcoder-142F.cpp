#include <algorithm>
#include <iostream>
using namespace std;
char grid[2001][2001];
int main()
{
    int t, n, m, x, y, ansn, ansm, ans;
    cin >> t;
    while (t--)
    {
        scanf("%d%d", &n, &m);
        x = n / 2;
        y = m / 2;
        ansn = x - 1;
        ansm = y - 1;
        ans = 1;
        for (int i = 0; i < n; i++)
            scanf("%s", grid[i]);
        for (int i = 0; i < x; i++)
            if (!(grid[i][0] == grid[n - 1 - i][0] &&
                  grid[i][0] == grid[i][m - 1] &&
                  grid[i][0] == grid[n - 1 - i][m - 1]))
            {
                ans = 0;
                break;
            }
        for (int i = 0; i < y; i++)
            if (!(grid[0][i] == grid[0][m - 1 - i] &&
                  grid[0][i] == grid[n - 1][i] &&
                  grid[0][i] == grid[n - 1][m - 1 - i]))
            {
                ans = 0;
                break;
            }
        if (ans)
        {
            for (int i = 0; i < x; i++)
            {
                for (int j = 0; j < y; j++)
                {
                    if (!(grid[i][j] == grid[i][m - 1 - j] &&
                          grid[i][j] == grid[n - 1 - i][j] &&
                          grid[i][j] == grid[n - 1 - i][m - 1 - j]))
                    {
                        ansm = min(ansm, j);
                        ansn = min(ansn, i);
                    }
                }
            }
            ans = ansm * ansn;
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
100
6 8
abcddcba
eqweewqe
frtyytrf
frtyytrf
eqweewqe
abcddcba

6 8
abcddcba
eqneewqe
fntyytrf
frtyytrf
eqweewqe
abcddcba
*/
