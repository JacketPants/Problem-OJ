#include <iostream>
using namespace std;
int main()
{
    int s, d, p;
    while (cin >> s >> d)
    {
        if (4 * s < d)
            p = 10 * s - 2 * d;
        else if (3 * s < 2 * d)
            p = 8 * s - 4 * d;
        else if (2 * s < 3 * d)
            p = 6 * s - 6 * d;
        else if (s < 4 * d)
            p = 3 * s - 9 * d;
        else
            p = -1;
        if (p < 0)
            cout << "Deficit" << endl;
        else
            cout << p << endl;
    }
    return 0;
}