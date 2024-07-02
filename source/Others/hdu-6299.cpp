#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    //greedy
    if (a.first >= a.second && b.first < b.second)
        return false;
    if (a.first < a.second && b.first >= b.second)
        return true;
    if (a.first < a.second && b.first < b.second)
        return a.first < b.first;
    return a.second > b.second;
}
char str[1000001];
stack<char> sta;
int main()
{
    int t, n, a, b, ans;
    cin >> t;
    while (t--)
    {
        vector<pair<int, int>> list;
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", str);
            sta.push(str[0]);
            for (int j = 1; str[j]; j++)
            {
                if (!sta.empty() && sta.top() == '(' && str[j] == ')')
                {
                    ans++;
                    sta.pop();
                }
                else
                    sta.push(str[j]);
            }
            a = b = 0;
            while (!sta.empty() && sta.top() == '(')
            {
                sta.pop();
                b++;
            }
            while (!sta.empty())
            {
                sta.pop();
                a++;
            }
            list.push_back(pair<int, int>(a, b));
        }
        sort(list.begin(), list.end(), cmp);
        int left = list[0].second, tem;
        for (int i = 1; i < n; i++)
        {
            tem = min(left, list[i].first);
            ans += tem;
            left += list[i].second - tem;
        }
        printf("%d\n", ans * 2);
    }
    return 0;
}