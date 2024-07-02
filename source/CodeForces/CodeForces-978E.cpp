#include <algorithm>
#include <iostream>
using namespace std;
int list[1000];
int main()
{
    int n, w, ans = 0;
    long long sum = 0, minn, maxn;
    scanf("%d%d", &n, &w);
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    minn = maxn = list[0];
    for (int i = 0; i < n; i++)
    {
        sum += list[i];
        maxn = max(maxn, sum);
        minn = min(minn, sum);
    }
    // cout << minn << endl;
    // cout << maxn << endl;
    if (minn < 0 && maxn < 0)
    {
        minn = -minn;
        maxn = -maxn;
        swap(minn, maxn);
        ans = w - maxn + 1;
    }
    else if (minn >= 0 && maxn >= 0)
    {
        ans = w - maxn + 1;
    }
    else
    {
        ans = w - (maxn - minn) + 1;
    }
    if (ans < 0)
        ans = 0;
    cout << ans << endl;
    return 0;
}