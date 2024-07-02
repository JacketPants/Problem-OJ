#include <algorithm>
#include <iostream>
#include <set>
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

set<pair<int, int>> pset, bset;

int main()
{
    char *ans;
    int t, n;
    long long x, y, a, b, maxx, minx, maxy, miny, maxa, mina, maxb, minb;
    cin >> t;
    while (t--)
    {
        pset.clear();
        bset.clear();
        maxx = maxy = maxa = maxb = -INF;
        minx = miny = mina = minb = INF;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            a = y - x;
            b = y + x;
            pset.insert(pair<int, int>(x, y));
            bset.insert(pair<int, int>(a, b));
            maxx = max(maxx, x);
            minx = min(minx, x);
            maxy = max(maxy, y);
            miny = min(miny, y);
            maxa = max(maxa, a);
            mina = min(mina, a);
            maxb = max(maxb, b);
            minb = min(minb, b);
        }
        ans = "No";
        if (pset.count(pair<int, int>(maxx, maxy)))
            ans = "Yes";
        else if (pset.count(pair<int, int>(maxx, miny)))
            ans = "Yes";
        else if (pset.count(pair<int, int>(minx, maxy)))
            ans = "Yes";
        else if (pset.count(pair<int, int>(minx, miny)))
            ans = "Yes";
        if (bset.count(pair<int, int>(maxa, maxb)))
            ans = "Yes";
        else if (bset.count(pair<int, int>(maxa, minb)))
            ans = "Yes";
        else if (bset.count(pair<int, int>(mina, maxb)))
            ans = "Yes";
        else if (bset.count(pair<int, int>(mina, minb)))
            ans = "Yes";
        puts(ans);
    }
    return 0;
}
