#include <iostream>
#define MOD 998244353LL
#define MAXN 200010

long long FACT[MAXN], IE[MAXN];

long long PowMod(long long a, long long i, long long mod = 1)
{
    if (i == 0)
        return 1 % mod;
    long long ans = PowMod(a, i >> 1, mod);
    ans = ans * ans % mod;
    if (i & 1)
        ans = ans * a % mod;
    return ans;
}

void InitC()
{
    FACT[0] = 1;
    for (long long i = 1; i < MAXN; i++)
        FACT[i] = (FACT[i - 1] * i) % MOD;
    IE[MAXN - 1] = PowMod(FACT[MAXN - 1], MOD - 2, MOD);
    for (long long i = MAXN - 1; i; i--)
        IE[i - 1] = IE[i] * i % MOD;
}

long long C(long long n, long long m, long long mod)
{
    if (n < 0 || m < 0 || n < m)
        return 0;
    return FACT[n] * IE[m] % mod * IE[n - m] % mod;
}

int main()
{
    InitC();
    int n, m, k, t, sum;
    long long ans;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &k);
        ans = 0;
        sum = k / n;
        for (int i = 0; i <= sum; i++)
        {
            if (i & 1)
                ans -= C(m, i, MOD) * C(k - i * n - 1 + m, m - 1, MOD) % MOD;
            else
                ans += C(m, i, MOD) * C(k - i * n - 1 + m, m - 1, MOD) % MOD;
            ans = (ans + MOD) % MOD;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
