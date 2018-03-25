#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char s[2000];
int dp[1234][1234];
int lpsDp(char *str, int n)
{
    int tmp;
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i)
        dp[i][i] = 1;
    for (int i = 1; i < n; ++i)
    {
        tmp = 0;
        for (int j = 0; j + i < n; j++)
        {
            if (str[j] == str[j + i])
                tmp = dp[j + 1][j + i - 1] + 2;
            else
                tmp = max(dp[j + 1][j + i], dp[j][j + i - 1]);
            dp[j][j + i] = tmp;
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int len;
    while (~scanf("%s", s))
    {
        len = strlen(s);
        for (int i = 0; i < len; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
        }
        printf("%d\n", strlen(s) - lpsDp(s, strlen(s)));
    }
    return 0;
}
