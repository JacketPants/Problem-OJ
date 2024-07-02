#include <algorithm>
#include <cmath>
#include <iostream>
#define INF 0x3f3f3f3f3f3f3f3fLL
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    long long n, p2, p3;
    long long ans;
    while (cin >> n >> p2 >> p3)
    {
        ans = INF;
        if (n < 3)
            ans = min(p2, p3);
        else
        {
            ans = min(ans, ((n / 2) + (bool)(n % 2)) * p2);
            ans = min(ans, ((n / 3) + (bool)(n % 3)) * p3);
            ans = min(ans, (((n - 3) / 2) + (bool)((n - 3) % 2)) * p2 + p3);
            ans = min(ans, (((n - 2) / 3) + (bool)((n - 2) % 3)) * p3 + p2);
            if (n > 4)
                ans = min(ans, (((n - 4) / 3) + (bool)((n - 4) % 3)) * p3 + 2 * p2);
            if (n > 6)
                ans = min(ans, (((n - 6) / 2) + (bool)((n - 6) % 2)) * p2 + 2 * p3);
        }
        cout << ans << endl;
    }
    return 0;
}