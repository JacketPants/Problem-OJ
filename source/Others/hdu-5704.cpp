#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int list[100];
int ans[100];
int main()
{
    int t, n, sum;
    cin >> t;
    while (t--)
    {
        memset(ans, 0, sizeof ans);
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", list + i);
            sum += list[i];
            ans[list[i]]++;
        }
        printf("%d %.2lf\n", 2 * sum / (3 * n - 2), 1.0 / (ans[2 * sum / (3 * n - 2)] + 1));
    }
    return 0;
}