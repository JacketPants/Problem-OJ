#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        putchar('1');
        while(--n)
            putchar('0');
        putchar('\n');
    }
    return 0;
}