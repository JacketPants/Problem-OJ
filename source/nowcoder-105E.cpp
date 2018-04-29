#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
vector<int> p;
map<int, int> list;
int main()
{
    int T, t, n, m, ans, tema, temb;
    scanf("%d", &T);
    while (T--)
    {
        p.clear();
        list.clear();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &tema, &temb);
            if (!list[tema])
                p.push_back(tema);
            list[tema] = max(list[tema], temb);
        }
        sort(p.begin(), p.end());
        for (int i = 1; i < p.size(); i++)
            list[p[i]] = max(list[p[i - 1]], list[p[i]]);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &t);
            ans = lower_bound(p.begin(), p.end(), t) - p.begin();
            printf("%d\n", (t == p[ans] ? list[p[ans]] : (ans ? list[p[ans - 1]] : 0)));
        }
    }
    return 0;
}
/*
4 10
1 100
5 10000
10 1000
1000000000 20000
1
9
10
1000000000
*/