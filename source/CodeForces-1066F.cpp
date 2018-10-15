#include <algorithm>
#include <iostream>
#define P pair<int, int>
using namespace std;
P list[200005];

bool cmp(P a, P b)
{
    int maxa = max(a.first, a.second);
    int maxb = max(b.first, b.second);
    if (maxa == maxb && (maxa & 1))
        return a < b;
    return maxa < maxb;
}
int main()
{
    int n;
    for (int i = 0; i < n; i++)
        scanf("%d%d", &list[i].first, &list[i].second);
    sort(list, list + n, cmp);
    return 0;
}