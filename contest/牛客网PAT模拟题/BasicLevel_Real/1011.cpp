#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    string num;
    map<char, int> mp;
    cin >> num;
    for (auto &th : num)
        mp[th]++;
    for (auto &th : mp)
        cout << th.first << ':' << th.second << endl;
    return 0;
}
