#include <iostream>
using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << n << endl;
        while(n--)
            cout << 1 << (n ? ' ' : '\n');
    }
    return 0;
}