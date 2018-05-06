#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> list;
    int n, cnt = 0;
    string s, ans, tem;
    cin >> n >> s;
    for (int i = 1; i < n; i++)
    {
        tem = s.substr(i - 1, 2);
        list[tem]++;
        if (list[tem] > cnt)
        {
            cnt = list[tem];
            ans = tem;
        }
    }
    cout << ans << endl;
    return 0;
}