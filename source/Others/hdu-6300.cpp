#include <algorithm>
#include <iostream>

using namespace std;

pair<pair<int, int>, int> list[5000];

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 3 * n; i; i--)
            scanf("%d%d", &list[i].first.first, &list[i].first.second), list[i].second = 3 * n - i + 1;
        sort(list + 1, list + 3 * n + 1);
        for (int i = 3 * n; i; i -= 3)
            printf("%d %d %d\n", list[i].second, list[i - 1].second, list[i - 2].second);
    }
    return 0;
}