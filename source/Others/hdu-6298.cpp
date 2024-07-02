#include <iostream>

using namespace std;

int main()
{
    int t;
    long long n;
    cin >> t;
    while (t--)
    {
        scanf("%lld", &n);
        if (!(n % 3))
            printf("%lld\n", (n / 3ll) * (n / 3ll) * (n / 3ll));
        else if (!(n % 4))
            printf("%lld\n", (n / 4ll) * (n / 4ll) * (n / 2ll));
        else
            puts("-1");
    }
    return 0;
}
