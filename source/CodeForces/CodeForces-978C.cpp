#include <algorithm>
#include <iostream>
using namespace std;
long long a[200010], b[200010];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    b[0] = 0;
    sort(b, b + m + 1);
    long long p = 1LL, q = 0LL;
    for (int i = 1; i <= m; i++)
    {
        q += b[i] - b[i - 1];
        while (q > a[p])
        {
            q -= a[p];
            p++;
        }
        printf("%I64d %I64d\n", p, q);
    }
    return 0;
}