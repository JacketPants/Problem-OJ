#include <iostream>

using namespace std;

int main()
{
    int t, L, v, l, r;
    cin >> t;
    while (t--)
    {
        cin >> L >> v >> l >> r;
        cout << L / v - r / v + (l - 1) / v << endl;
    }
    return 0;
}
