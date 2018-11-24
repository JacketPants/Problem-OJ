#include <iostream>

using namespace std;

int main()
{
    char a[100], b[100];
    int cnta = 0, cntb = 0, ans = 0, da, db;
    cin >> a >> da >> b >> db;
    for (auto &th : a)
    {
        if (th == da + '0')
            cnta++;
    }
    for (auto &th : b)
    {
        if (th == db + '0')
            cntb++;
    }
    for (int i = 0; i < cnta; i++)
    {
        ans += da;
        da *= 10;
    }
    for (int i = 0; i < cntb; i++)
    {
        ans += db;
        db *= 10;
    }
    cout << ans << endl;
    return 0;
}
