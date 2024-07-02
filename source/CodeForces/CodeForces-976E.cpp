#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;
pair<long long, long long> list[200005];
int n, a, b;
long long m;
bool cmp(pair<long long, long long> x, pair<long long, long long> y)
{
    return x.first - x.second > y.first - y.second;
}
bool cmpb(pair<long long, long long> x, pair<long long, long long> y)
{
    // if (x.first * m - x.second == y.first * m - y.second)
    //     return x.first - x.second > y.first - y.second;
    return (x.first * m - x.second) - (x.first - x.second) < (y.first * m - y.second) - (x.first - x.second);
}
int main()
{
    long long ans;
    int tem;
    while (~scanf("%d%d%d", &n, &a, &b))
    {
        ans = 0;
        for (int i = 0; i < n; i++)
            scanf("%I64d%I64d", &list[i].first, &list[i].second);
        m = 1LL << a;
        sort(list, list + n, cmp);
        tem = max_element(list, list + n, cmpb) - list;
        list[tem].first *= m;
        for (int i = 0; i < b; i++)
            ans += max(list[i].first, list[i].second);
        for (int i = b; i < n; i++)
            ans += list[i].second;
        cout << ans << endl;
    }
    return 0;
}
// #include <algorithm>
// #include <cctype>
// #include <cstdio>
// #include <cstring>
// #include <iostream>
// #define LL long long
// using namespace std;
// int n, A, B, t;
// LL Ans, Sum, Num;
// struct xcw
// {
//     LL hp, dam;
//     bool operator<(const xcw b) const { return (hp - dam) > (b.hp - b.dam); }
// } a[200005];
// LL read()
// {
//     LL ret = 0;
//     char ch = getchar();
//     bool f = 1;
//     for (; !isdigit(ch); ch = getchar())
//         f ^= !(ch ^ '-');
//     for (; isdigit(ch); ch = getchar())
//         ret = ret * 10 + ch - '0';
//     return ret;
// }
// int main()
// {
//     //  freopen("E.in","r",stdin);
//     //  freopen("E.out","w",stdout);
//     n = read(), A = read(), B = read();
//     for (int i = 1; i <= n; i++)
//         a[i] = (xcw){read(), read()}, Num += a[i].dam;
//     if (!B)
//     {
//         cout << Num << endl;
//         return 0;
//     }
//     sort(a + 1, a + 1 + n);
//     for (int i = 1; i <= B; i++)
//         Sum += max(0LL, a[i].hp - a[i].dam);
//     for (int i = 1; i <= B; i++)
//         Ans = max(Ans, Sum - max(0LL, a[i].hp - a[i].dam) - a[i].dam + (a[i].hp << A));
//     for (int i = B + 1; i <= n; i++)
//         Ans = max(Ans, Sum - max(0LL, a[B].hp - a[B].dam) - a[i].dam + (a[i].hp << A));
//     cout << Ans + Num << endl;
//     return 0;
// }