#include <iostream>
using namespace std;
int main()
{
    int n, a, b, c, t, ans;
    int list[1001];
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &t);
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    ans = n * a;
    if (c > b)
        for (int i = 0; i < n; i++)
            ans += (t - list[i]) * (c - b);
    printf("%d\n", ans);
    return 0;
}