#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> list, cnt, ans;
int main()
{
    int t, n, m, tem, sum, sumt, out, maxn;
    cin >> t;
    while (t--)
    {
        list.clear();
        cnt.clear();
        ans.clear();
        sumt = sum = maxn = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tem);
            list[tem]++;
        }
        for (auto i : list)
        {
            cnt[i.second]++;
        }

        for (int i = n; i > 0; i--)
        {
            sum += sumt;
            if (cnt[i])
            {
                sumt += cnt[i];
                ans[i] = sum + sumt - 1;
            }
            // ans[i] = ans[i + 1] + (bool)ans[i + 1] + sum + cnt[i] - 1;
            // sum += cnt[i];
        }
        out = -1;
        for (auto i : list)
        {
            if (ans[i.second] <= m)
                out = max(out, i.first);
        }
        printf("%d\n", out);
    }
    return 0;
}

/*
2 2 
1 1


29 8
9 9 9 9 9
8 8 8 8 8
7 7 7 7 7
6 6 6 6 6
10 10 10 10
3 3 3 3
4
*/
