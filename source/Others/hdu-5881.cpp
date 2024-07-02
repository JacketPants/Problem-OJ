#include <iostream>
using namespace std;

int main()
{
    long long l, r, n;
    while (cin >> l >> r)
    {
        if (r <= 1)
            n = 0;
        else if (r <= 2)
            n = 1;
        else if (l <= 1)
            n = (r - 1) / 2 + 1;
        else if (r - l <= 2)
            n = 2;
        else
            n = (r - l) / 2 + 1;
        cout << n << endl;
    }
    return 0;
}