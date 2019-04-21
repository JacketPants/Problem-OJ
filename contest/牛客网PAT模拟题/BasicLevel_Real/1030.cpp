#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int a, b, c;
    for (auto &ch : s)
    {
        if (ch == 'P')
        {
            a++;
            a %= 1000000007;
        }
        else if (ch == 'A')
        {
            b += a;
            b %= 1000000007;
        }
        else
        {
            c += b;
            c %= 1000000007;
        }
    }
    cout << c << endl;
    return 0;
}