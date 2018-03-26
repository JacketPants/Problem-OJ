#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dp[1001][1001];
int main()
{
    int lena, lenb;
    char a[1005], b[1005];
    memset(dp, 0, sizeof dp);
    while (~scanf("%s%s", a + 1, b + 1))
    {
        lena = strlen(a);
        lenb = strlen(b);
        for (int i = 1; i < lena; i++)
            for (int j = 1; j < lenb; j++)
                dp[i][j] = (a[i] == b[j] ? (dp[i - 1][j - 1] + 1) : max(dp[i][j - 1], dp[i - 1][j]));
        printf("%d\n", dp[lena - 1][lenb - 1]);
    }
    return 0;
}