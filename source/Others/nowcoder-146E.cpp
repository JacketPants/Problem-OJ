#include <iostream>

using namespace std;

int main()
{
    int n, m, k, ans, sum, t;
    int a, b, c, d;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        ans = n * m;
        sum = 1;
        for (int i = 0; i < k; i++)
        {
            cin >> a >> b >> c >> d;
            if (a == b && b == c && c == d)
                continue;
            if (a == 1 && b == 1)
            {
                if ((c - 1 + d - 1) % 2 == 0)
                    sum = 0;
            }
            else if (c == 1 && d == 1)
            {
                if ((a - 1 + b - 1) % 2 == 0)
                    sum = 0;
            }
            else if ((a - 1 + b - 1) % 2 == 0)
            {
                if ((c - 1 + d - 1) % 2 == 0)
                    sum = 0;
            }
            else if ((c - 1 + d - 1) % 2 == 0)
            {
                if ((a - 1 + b - 1) % 2 == 0)
                    sum = 0;
            }
        }
        if (n % 2 && m % 2)
            cout << ans + sum << endl;
        else
            cout << ans << endl;
    }
    return 0;
}