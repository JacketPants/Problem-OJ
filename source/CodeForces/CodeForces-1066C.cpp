#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, id, cntl = 0, cntr = 0;
    char od;
    map<int, int> mp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> od >> id;
        if (!i)
        {
            mp[id] = 0;
            cntl--;
            cntr++;
            continue;
        }
        if (od == 'L')
            mp[id] = cntl--;
        else if (od == 'R')
            mp[id] = cntr++;
        else
            cout << min(mp[id] - cntl, cntr - mp[id]) - 1 << endl;
    }
    return 0;
}
