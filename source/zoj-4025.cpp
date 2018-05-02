#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>

using namespace std;

int d[100000], s[100000];
map<int, int> list;
int main()
{
    int t, n, ans;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        list.clear();
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", d + i);
        for (int i = 0; i < n; i++)
            scanf("%d", s + i);
        for (int i = 0; i < n; i++)
            ans = max(ans, ++list[s[i] - d[i]]);
        printf("%d\n", ans);
    }
    return 0;
}