#include <iostream>
using namespace std;
int main()
{
    int t, n, ans, m;
    cin >> t;
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            ans+=m;
        }
        printf("%d\n", ans / n);
    }
    return 0;
}