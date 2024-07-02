#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
pair<int, string> list[10];
int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> list[i].second >> list[i].first;
        sort(list, list + n);
        for (int i = n - 1; i >= 0; i--)
            cout << list[i].second << (i ? ' ' : '\n');
    }
    return 0;
}