#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
struct G
{
    int a, b;
    bool operator<(const G &x) const
    {
        if (a == x.a)
            return b < x.b;
        return a < x.b;
    }
};
int db[10010][12];
map<string, int> to;
int main()
{
    int n, m, p, tp = 0;
    G tem;
    string s;
    char ch, out[10000];
    bool isYES;
    while (cin >> n >> m)
    {
        to.clear();
        isYES = p = 1;
        getchar();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m;)
            {
                ch = getchar();
                if (ch == ',')
                {
                    if (!to[s])
                        to[s] = p++;
                    db[i][j++] = to[s];
                    s.clear();
                    continue;
                }
                else if (ch == '\n')
                {
                    if (!to[s])
                        to[s] = p++;
                    db[i][j++] = to[s];
                    s.clear();
                    break;
                }
                s.push_back(ch);
            }
        for (int i = 1; i <= m; i++)
            for (int j = i + 1; j <= m; j++)
            {
                map<G, int> list;
                for (int k = 1; k <= n; k++)
                {
                    tem.a = db[k][i];
                    tem.b = db[k][j];
                    if (list.count(tem))
                    {
                        tp += sprintf(out + tp, "NO\n%d %d\n%d %d\n", list[tem], k, i, j);
                        isYES = false;
                        goto out;
                    }
                    list[tem] = k;
                }
            }
    out:
        if (isYES)
            tp += sprintf(out + tp, "YES\n");
    }
    printf(out);
    return 0;
}
