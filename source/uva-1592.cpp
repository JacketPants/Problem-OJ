#include <iostream>
#include <map>
#include <string>
using namespace std;
int db[10001][11];
struct G
{
    int a, b;
    bool operator<(const G& x)
    {
        if (a == x.a)
            return b < x.b;
        return a < x.a;
    }
};
int main()
{
    int n, m, cnt;
    G tem;
    string s;
    map<string, int> t;
    while (~scanf("%d%d", &n, &m))
    {
        t.clear();
        cnt = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                cin >> s;
                if (!t[s])
                    t[s] = cnt++;
                db[i][j] = t[s];
            }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                map<G, int> list;
                for (int k = 1; k <= n; k++)
                {
                    tem.a = db[k][i];
                    tem.b = db[k][j];
                    if (list[tem])
                    {
                        printf("%d %d\n%d %d", list[tem], k, i, j);
                        // goto out;
                    }
                    else
                    {
                        list[tem] = k;
                    }
                }
            }
        }
        // out:;
    }
    return 0;
}