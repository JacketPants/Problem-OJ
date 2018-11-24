#include <iostream>
using namespace std;
int main()
{
    double n, m;
    char ch;
    cin >> n >> ch;
    m = int(n / 2 + 0.5);
    for (int i = 0; i < n; i++)
        putchar(ch);
    putchar('\n');
    for (int i = 2; i < m; i++)
    {
        putchar(ch);
        for (int j = 2; j < n; j++)
            putchar(' ');
        putchar(ch);
        putchar('\n');
    }
    for (int i = 0; i < n; i++)
        putchar(ch);
    putchar('\n');
    return 0;
}