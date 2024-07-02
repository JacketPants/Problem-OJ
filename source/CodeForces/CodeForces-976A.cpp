#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    bool is = false;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            cnt++;
        else
            is = true;
    }
    if (is)
        cout << '1';
    for (int i = 0; i < cnt; i++)
        cout << '0';
    cout << endl;
    return 0;
}
