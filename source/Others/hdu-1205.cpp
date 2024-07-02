#include <iostream>
using namespace std;
int main()
{
    int t, n, tem, max;
    long long cnt;
    cin >> t;
    while (t--)
    {
        cnt = max = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tem);
            max = max < tem ? tem : max;
            cnt += tem;
        }
        if (cnt + 1 < max * 2)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}