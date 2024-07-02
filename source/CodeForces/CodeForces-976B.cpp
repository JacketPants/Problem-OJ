#include <iostream>
using namespace std;
int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    if (k < n)
        cout << k + 1 << ' ' << 1 << endl;
    else
    {
        k -= n;
        if ((k / (m - 1)) % 2LL)
            cout << n - (k / (m - 1)) << ' ' << m - (k % (m - 1)) << endl;
        else
            cout << n - (k / (m - 1)) << ' ' << 2LL + (k % (m - 1)) << endl;
    }
    return 0;
}
