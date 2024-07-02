#include <cstring>
#include <iostream>
#include <string>
using namespace std;
const char p[6][6] = {{'0', '1', '2', '3', '4', '5'},
                      {'6', '7', '8', '9', 'A', 'B'},
                      {'C', 'D', 'E', 'F', 'G', 'H'},
                      {'I', 'J', 'K', 'L', 'M', 'N'},
                      {'O', 'P', 'Q', 'R', 'S', 'T'},
                      {'U', 'V', 'W', 'X', 'Y', 'Z'}};
int cnt[2][6];
void Search(char ch)
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            if (ch == p[i][j])
            {
                cnt[0][i]++;
                cnt[1][j]++;
                return;
            }
}
int main()
{
    int t, maxa, maxb;
    string s;
    scanf("%d", &t);
    while (t--)
    {
        maxa = maxb = 0;
        memset(cnt, 0, sizeof cnt);
        cin >> s;
        for (int i = 0; i < s.length(); i++)
            Search(s[i]);
        for (int i = 0; i < 6; i++)
            maxa = max(maxa, cnt[0][i]);
        for (int i = 0; i < 6; i++)
            maxb = max(maxb, cnt[1][i]);
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                if (cnt[0][i] == maxa && cnt[1][j] == maxb)
                    putchar(p[i][j]);
        putchar('\n');
    }
    return 0;
}