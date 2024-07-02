#include <algorithm>
#include <iostream>
using namespace std;
int l[200000], r[200000];
int main()
{
    int n;
    cin >> n;
    long long ans = n;
    for (int i = 0; i < n; i++)
        scanf("%d%d", l + i, r + i);
    sort(l, l + n);
    sort(r, r + n);
    for (int i = 0; i < n; i++)
        ans += max(l[i], r[i]);
    cout << ans;
    return 0;
}