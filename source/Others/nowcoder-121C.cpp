#include <algorithm>
#include <iostream>
using namespace std;
int a[1010], b[1010];
int n, m, sum = 0, tem, ans = 0;
int dfs(int x, int a, int b, int c)
{
    if ()
}
int main()
{
    scanf("%d", &n);
    m = n - 1;
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &tem);
        sum += tem;
    }
    ans = a[0];
    sort(a, a + n);
    ans += a[n - 1];
    ans += a[n - 2];
    if (ans < sum)
        puts("-1");
    else
        printf("%d\n", ans - sum);
    return 0;
}