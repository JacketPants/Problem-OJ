#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int g[30][30], n;
int d[2][30];
int pre[30];
int Find(int x)
{
    int r = x;
    while (pre[r] != r)
        r = pre[r];
    int s = x, t;
    while (s != r)
    {
        t = pre[s];
        pre[s] = r;
        s = t;
    }
    return r;
}
void Unionfind()
{
    int a, b;
    for (int i = 1; i <= 26; i++)
        pre[i] = i;
    for (int i = 1; i <= 26; i++)
        for (int j = 1; j <= 26; j++)
            if (g[i][j] > 0)
            {
                a = Find(i);
                b = Find(j);
                if (a != b)
                    pre[max(a, b)] = min(a, b);
            }
    for (int i = 1; i <= 26; i++)
        Find(i);
}
int main()
{
    int t, tem, p = 0;
    char out[100000];
    bool isEuler;
    string s;
    cin >> t;
    while (t--)
    {
        tem = 0;
        isEuler = true;
        memset(g, 0, sizeof g);
        memset(d, 0, sizeof d);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            g[s[s.length() - 1] - 'a' + 1][s[0] - 'a' + 1] = g[s[0] - 'a' + 1][s[s.length() - 1] - 'a' + 1]++;
            d[0][s[0] - 'a' + 1]++;
            d[1][s[s.length() - 1] - 'a' + 1]++;
        }
        Unionfind();
        // for (int i = 1; i <= 26; i++)
            // cout << pre[i] << ' ';
        for (int i = 1; i <= 26 && isEuler; i++)
        {
            if (d[0][i] || d[1][i])
            {
                if (tem)
                    isEuler = (tem == pre[i]);
                else
                    tem = pre[i];
            }
        }
        bool isA = true, isB = true;
        for (int i = 1; i <= 26 && isEuler; i++)
            if (d[0][i] != d[1][i])
            {
                if (d[0][i] - d[1][i] == 1 && isA)
                    isA = false;
                else if (d[1][i] - d[0][i] == 1 && isB)
                    isB = false;
                else
                    isEuler = false;
            }
        if (isEuler)
            p += sprintf(out + p, "Ordering is possible.\n");
        else
            p += sprintf(out + p, "The door cannot be opened.\n");
    }
    printf(out);
    return 0;
}