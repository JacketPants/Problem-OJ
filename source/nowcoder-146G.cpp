#include <bits/stdc++.h>
const long long mod = 1000000007LL;
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
        a = (42LL * n) % mod;
        b = (23LL * powmod(n, 2)) % mod;
        c = (6LL * powmod(n, 3)) % mod;
        d = powmod(n, 4) % mod;
        e = powmod(24LL, mod - 2) % mod;
        // ans = (((24LL + b + d + mod) % mod) * e) % mod - (((a + c + mod) % mod) * e) % mod;
        ans = (((24LL - a + b - c + d) % mod) * (powmod(24, mod - 2) % mod)) % mod;
        cout << (ans + mod) % mod << endl;
    }
    // (24 - 42n + 23n^2 - 6n^3 + n^4)/24
    // ((24 - 42n + 23n^2 - 6n^3 + n^4)*powmod(24,mod-2))%mod
    // (((24 - 42n + 23n^2 - 6n^3 + n^4)%mod)*(powmod(24,mod-2)%mod))%mod
    return 0;
}