#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
bool cmp(string a, string b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}
char p[100][100];
string dp[71][71], ans;
int main()
{
    int w, h;
    while (~scanf("%d%d", &w, &h) && (w || h))
    {
        for (int i = 0; i < 71; i++)
            for (int j = 0; j < 71; j++)
                dp[i][j].clear();
        ans.clear();
        for (int i = 1; i <= h; i++)
            scanf("%s", &p[i][1]);
        /*
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if ()
                    p[i][j] = 0;*/
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                if (p[i][j] >= 'A' && p[i][j] <= 'Z')
                    continue;
                if (cmp(dp[i - 1][j], dp[i][j - 1]))
                    dp[i][j] = dp[i][j - 1] + p[i][j];
                else
                    dp[i][j] = dp[i - 1][j] + p[i][j];
                if (dp[i][j] == "0")
                    dp[i][j].clear();
            }
        }
        for (int i = 1; i <= h; i++)
            for (int j = 1; j <= w; j++)
                if (cmp(ans, dp[i][j]))
                    ans = dp[i][j];
        cout << ans << endl;
    }
    return 0;
}