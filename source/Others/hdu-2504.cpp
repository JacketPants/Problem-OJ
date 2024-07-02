#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}
int main()
{
    int t, a, b, i;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        for (i = 2 * b; i < 2 * a; i++)
            if (GCD(a, i) == b)
                break;
        cout << i << '\n';
    }
    return 0;
}