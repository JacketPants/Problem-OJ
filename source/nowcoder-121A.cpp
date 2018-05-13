#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
struct G
{
    int p;
    string n;
};
bool cmp(G x, G y)
{
    if (x.p == y.p)
        return x.n > y.n;
    return x.p > y.p;
}
G list[1000];
int main()
{
    int t, n, k;
    cin >> t;
    for (int j = 1; j <= t; j++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> list[i].n >> list[i].p;
        sort(list, list + n, cmp);
        cin >> k;
        cout << '#' << j << ": " << list[k - 1].n << ' ' << list[k - 1].p << endl;
    }
    return 0;
}
/*
2
3
Apple 18
Book 30
Milk 8000
3
4
Apple 300
Bananas  200
Bracelet 200
Candy 200
3
*/