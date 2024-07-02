#include <iostream>

using namespace std;
int grid[300][300];
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        scanf("%d", &n);
        if (n % 2)
            puts("impossible");

        else
        {
            puts("possible");
            for (int i = n / 2; i; i--)
                for (int j = 1; j <= n; j++)
                    grid[i][j] = 1;
            for (int i = n / 2 + 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    grid[i][j] = -1;
            for (int i = n / 2; i > 1; i--)
                for (int j = n - i + 2; j <= n; j++)
                    grid[i][j] = 0;
            for (int i = n / 2 + 1; i <= n; i++)
                for (int j = n + 1 - i; j; j--)
                    grid[i][j] = 0;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    printf("%d%c", grid[i][j], j == n ? '\n' : ' ');
        }
    }
    return 0;
}
/*
1   1   1   1
1   1   1   0
0   0   -1  -1
0   -1  -1  -1

1   1   1   1   1   1   6
1   1   1   1   1   0   5
1   1   1   1   0   0   4
0   0   0   -1  -1  -1  -3
0   0   -1  -1  -1  -1  -4
0   -1  -1  -1  -1  -1  -5
3   2   1   0   -1  -2
*/