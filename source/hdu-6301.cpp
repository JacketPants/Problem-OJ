#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

set<int> useful;
int main()
{
    int t, n, m, l, r;
    cin >> t;
    while (t--)
    {
        scanf("%d%d", &n, &m);
        vector<int> end(n + 1);
        vector<int> ans;
        iota(end.begin(), end.end(), 0);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &l, &r);
            end[l] = max(r, end[l]);
        }
        for (int i = 1; i <= n; i++)
            useful.insert(i);
        l = 1;
        r = 0;
        for (int i = 1; i <= n; i++)
        {
            if (end[i] <= r)
                continue;
            while (l < i)
                useful.insert(ans[l++ - 1]);
            while (end[i] != r)
            {
                ans.push_back(*useful.begin());
                useful.erase(ans[r++]);
            }
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", ans[i], (i == n - 1 ? '\n' : ' '));
    }
    return 0;
}
