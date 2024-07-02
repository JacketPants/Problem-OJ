#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n, t, x;
    bool is;
    string s;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        cin >> s;
        if (n == 1)
        {
            cout << s << '\n';
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                is = x = 1;
                for (int j = 0; i + j - 1 < s.length(); j += x)
                {
                    if (x)
                        putchar(s[i + j - 1]);
                    if (is)
                    {
                        x = 2 * (n - i);
                        is = !is;
                    }
                    else
                    {
                        x = 2 * (i - 1);
                        is = !is;
                    }
                }
            }
            putchar('\n');
        }
    }
    return 0;
}