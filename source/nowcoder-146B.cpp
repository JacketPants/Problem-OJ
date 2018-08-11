#include <bits/stdc++.h>
const long long mod = 998244353LL;
long long powmod(long long a, long long b)
{
    long long res = 1;
    a %= mod;
    assert(b >= 0);
    for (; b; b >>= 1)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
    }
    return res;
}
using namespace std;

int main()
{
    long long n, a, b, c, d, e, ans;
    while (cin >> n)
    {
        a = powmod(4LL, n);
        b = (a + 2) % mod;
        ans = (b * powmod(3, mod - 2)) % mod;
        cout << (ans + mod) % mod << endl;
    }
    //  (4^n + 2)/3
    return 0;
}