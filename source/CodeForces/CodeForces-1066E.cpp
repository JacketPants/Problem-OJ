#include <iostream>
#include <string>
#define MOD 998244353
using namespace std;
int main()
{
    int n, m, ans = 0, pw = 1, sum = 0;
    string a, b;
    cin >> n >> m >> a >> b;
    for (int i = 0; i < m; i++)
    {
        if (i < n && a[n - 1 - i] == '1')
            sum = (sum + pw) % MOD;
        if (b[m - 1 - i] == '1')
            ans = (ans + sum) % MOD;
        pw = (pw + pw) % MOD;
    }
    cout << ans << endl;
    return 0;
}