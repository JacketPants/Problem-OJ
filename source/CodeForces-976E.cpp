#include <algorithm>
#include <iostream>

using namespace std;
pair<int, int> list[200000];
int n, a, b;
bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first * a - x.second > y.first * a - y.second;
}
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < n; i++)
            scanf("%d%d", &list[i].first, &list[i].second);
        sort(list, list + n, cmp);
    }
    return 0;
}