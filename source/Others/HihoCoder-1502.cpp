#include <iostream>
int main()
{
    int n, m, k, ans = 0;
    int s[300][300] = {0};
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &s[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
    for (int a = n; a >= 1; a--)
        for (int b = m; b >= 1; b--)
            for (int x = 0; x + a <= n; x++)
                for (int y = 0; y + b <= m; y++)
                    if (ans < a * b &&
                        s[x + a][y + b] + s[x][y] - s[x + a][y] - s[x][y + b] <= k)
                        ans = a * b;
    std::cout << ans;
    return 0;
}
