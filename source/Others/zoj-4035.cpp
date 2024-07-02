#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Word
{
    string s;
    long long v;
};
bool cmp(Word a, Word b)
{
    if (a.v == b.v)
        return a.s > b.s;
    return a.v < b.v;
}
Word list[101];

int main()
{
    // std::ios::sync_with_stdio(false);
    int t, n, m, tem;
    long long ans;
    cin >> t;
    while (t--)
    {
        ans = 0;
        cin >> n >> m;
        tem = n - m;
        for (int i = 1; i <= n; i++)
            cin >> list[i].s >> list[i].v;
        sort(list + 1, list + n + 1, cmp);
        for (int i = m; i; i--)
            ans += (list[i + tem].v * i);
        cout << ans;
        for (int i = m; i; i--)
            cout << " " << list[i + tem].s;
        cout << endl;
    }
    return 0;
}
/*
4
10 8
hello 0
world 0
behind 0
far 1
be 2
spring 10
can 15
comes 20
winter 25
if 200
5 5
collegiate 0
programming -5
zhejiang 10
provincial 5
contest -45
3 2
bcda 1
bcd 1
bbbbb 1
3 2
a 1
aa 1
aaa 1
*/