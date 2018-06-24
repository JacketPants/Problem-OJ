#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, w, tem, sum = 0, minn = 0, maxn = 0;
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tem);
        sum += tem;
        if (sum > 0)
            maxn = max(sum, maxn);
        else if (sum < 0)
            minn = min(sum, minn);
    }
    minn = -minn;
    if (minn <= w - maxn)
        printf("%d\n", w - maxn - minn + 1);
    else
        puts("0");
    return 0;
}