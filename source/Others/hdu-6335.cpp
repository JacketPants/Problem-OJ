#include <algorithm>
#include <iostream>
using namespace std;

long long  list[100];
int main()
{
    int t, n, m, ans;
    long long sum;
    cin >> t;
    while (t--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            scanf("%*d%lld", list + i);
        sort(list, list + n);
        sum = 1LL;
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            sum *= list[i] + 1LL;
            if (sum > m)
                break;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}