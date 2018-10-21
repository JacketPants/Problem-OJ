#include <algorithm>
#include <iostream>
using namespace std;
int r[100001], t[100001];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", r + i);
    for (int i = 0; i < n; i++)
        scanf("%d", t + i);
    sort(r, r + n);
    sort(t, t + n);
    int p = n - 1, ans = 0;
    for (int i = n - 1; i >= 0 && p >= 0; i--)
    {
        while (p > 0 && r[i] < t[p])
            p--;
        if (r[i] >= t[p])
        {
            ans++;
            p--;
        }
    }
    cout << ans << endl;
    return 0;
}
/*
1 2 3 4 6
2 4 5 6 6
*/
