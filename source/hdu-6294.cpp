#include <iostream>
#include <string>
using namespace std;
bool list[1000000];
int main()
{
    ios::sync_with_stdio(false);
    int t, len;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> len >> s;
        list[s.length() - 1] = true;
        for (int i = len - 2; i >= 0; i--)
        {
            if (s[i] < s[i + 1])
                list[i] = false;
            else if (s[i] > s[i + 1])
                list[i] = true;
            else
                list[i] = list[i + 1];
        }
        for (int i = 0; i < len - 1; i++)
            if (!list[i])
                cout << '<';
            else
                cout << '>';
        cout << endl;
    }
    return 0;
}
