#include <cstring>
#include <iostream>
using namespace std;
char g[12][12], t[12][12];
int a, b;
bool Judge()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (g[i][j] == 'R' || g[i][j] == 'G')
            {
                for (int k = i + 1; k <= 10; k++)
                    if (g[k][j] == '.' || g[k][j] == 'x')
                        g[k][j] = 'x';
                    else
                        break;
                for (int k = i - 1; k; k--)
                    if (g[k][j] == '.' || g[k][j] == 'x')
                        g[k][j] = 'x';
                    else
                        break;
                for (int k = j + 1; k <= 9; k++)
                    if (g[i][k] == '.' || g[i][k] == 'x')
                        g[i][k] = 'x';
                    else
                        break;
                for (int k = j - 1; k; k--)
                    if (g[i][k] == '.' || g[k][j] == 'x')
                        g[i][k] = 'x';
                    else
                        break;
            }
            else if (g[i][j] == 'H')
            {
                if (g[i + 1][j] == '.' || g[i + 1][j] == 'x')
                    g[i + 2][j + 1] = g[i + 2][j - 1] = 'x';
                if (g[i - 1][j] == '.' || g[i - 1][j] == 'x')
                    g[i - 2][j + 1] = g[i - 2][j - 1] = 'x';
                if (g[i][j + 1] == '.' || g[i][j + 1] == 'x')
                    g[i + 1][j + 2] = g[i - 1][j + 2] = 'x';
                if (g[i][j - 1] == '.' || g[i][j - 1] == 'x')
                    g[i + 1][j - 2] = g[i - 1][j - 2] = 'x';
            }
            else if (g[i][j] == 'C')
            {
                for (int k = i + 1; k <= 10; k++)
                    if (g[k][j] != '.' && g[k][j] != 'x')
                    {
                        for (int l = k + 1; l <= 10; l++)
                            if (g[l][j] == '.' || g[l][j] == 'x')
                                g[l][j] = 'x';
                            else
                                break;
                        break;
                    }
                for (int k = i - 1; k; k--)
                    if (g[k][j] != '.' && g[k][j] != 'x')
                    {
                        for (int l = k - 1; l; l--)
                            if (g[l][j] == '.' || g[l][j] == 'x')
                                g[l][j] = 'x';
                            else
                                break;
                        break;
                    }
                for (int k = j + 1; k <= 9; k++)
                    if (g[i][k] != '.' && g[i][k] != 'x')
                    {
                        for (int l = k + 1; l <= 9; l++)
                            if (g[i][l] == '.' || g[i][l] == 'x')
                                g[i][l] = 'x';
                            else
                                break;
                        break;
                    }
                for (int k = j - 1; k; k--)
                    if (g[i][k] != '.' && g[i][k] != 'x')
                    {
                        for (int l = k - 1; l; l--)
                            if (g[i][l] == '.' || g[i][l] == 'x')
                                g[i][l] = 'x';
                            else
                                break;
                        break;
                    }
            }
            // else if (g[i][j] == 'G')
            // {
            //     for (int k = i - 1; k; k--)
            //         if (g[k][j] == '.' || g[k][j] == 'x')
            //             g[k][j] = 'x';
            //         else
            //             break;
            // }
        }
    }
    if (g[a][b] == 'x')
        return false;
    else
        return true;
}
int main()
{
    int n, x, y, z;
    bool ans;
    char ch;
    memset(g, 'x', sizeof g);
    while (cin >> n >> a >> b && (n || a || b)) //(~scanf("%d%d%d", &n, &a, &b) && (n || a || b))
    {
        z = ans = false;
        memset(t, '.', sizeof t);
        for (int i = 0; i < n; i++)
        {
            cin >> ch >> x >> y;
            t[x][y] = ch;
            if (ch == 'G')
                z = y;
        }
        if (z && !ans)
        {
            if (b == z)
            {
                ans = true;
                for (int i = a; i <= 10; i++)
                    if (t[i][z] != 'G' || t[i][z] != '.')
                    {
                        ans = false;
                        break;
                    }
            }
        }
        if (!ans && a < 3)
        {
            a++;
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 9; j++)
                    g[i][j] = t[i][j];
            g[a][b] = '.';
            ans = Judge();
            // cout << ans;
            a--;
        }
        if (!ans && a > 1)
        {
            a--;
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 9; j++)
                    g[i][j] = t[i][j];
            g[a][b] = '.';
            ans = Judge();
            // cout << ans;
            a++;
        }
        if (!ans && b < 6)
        {
            b++;
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 9; j++)
                    g[i][j] = t[i][j];
            g[a][b] = '.';
            ans = Judge();
            // cout << ans;
            b--;
        }
        if (!ans && b > 4)
        {
            b--;
            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 9; j++)
                    g[i][j] = t[i][j];
            g[a][b] = '.';
            ans = Judge();
            // cout << ans;
            b++;
        }
        if (ans)
            puts("NO");
        else
            puts("YES");
    }
    return 0;
}