#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>
#define P pair<int, int>
#define int long long
using namespace std;
int dis(P a, P b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}
map<int, vector<P>> mp;
int main()
{
    int n, x, y, dl, dr, dd, ansl = 0, ansr = 0;
    P nl, nr, ll(0, 0), lr(0, 0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld%lld", &x, &y);
        mp[max(x, y)].emplace_back(P(x, y));
    }
    for (auto &it : mp)
    {
        sort(it.second.begin(), it.second.end(), [](P a, P b) {
            return P(a.first, -a.second) < P(b.first, -b.second);
        });
        nl = *it.second.begin();
        nr = it.second.back();
        dd = dis(nl, nr);
        dl = min(ansl + dis(ll, nr) + dd, ansr + dis(lr, nr) + dd);
        dr = min(ansl + dis(ll, nl) + dd, ansr + dis(lr, nl) + dd);
        ansl = dl;
        ansr = dr;
        ll = nl;
        lr = nr;
    }
    cout << min(ansl, ansr) << endl;
    return 0;
}
