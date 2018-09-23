#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<int, int> mp;
int main()
{
    int n, hsh;
    long long ans = 0;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        hsh = 0;
        for (char ch : s)
            hsh ^= 1 << (ch - 'a');
        ans += mp[hsh];
        for (char ch = 'a'; ch <= 'z'; ch++)
            ans += mp[hsh ^ (1 << (ch - 'a'))];
        mp[hsh]++;
    }
    cout << ans << endl;
    return 0;
}