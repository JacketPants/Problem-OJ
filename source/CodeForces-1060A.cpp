#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, cnt = 0;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '8')
            cnt++;
    if (cnt < s.length() / 11)
        cout << cnt << endl;
    else
        cout << s.length() / 11 << endl;
    return 0;
}
