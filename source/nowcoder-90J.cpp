#include <algorithm>
#include <iostream>
using namespace std;
int list[100001];
int main()
{
    int t, n, ans;
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", list + i);
        sort(list, list + n);
        for (int i = 1; i < n; i++)
            ans += list[i] - list[0];
        printf("%d %d\n", ans, ans + list[0]);
    }
    return 0;
}