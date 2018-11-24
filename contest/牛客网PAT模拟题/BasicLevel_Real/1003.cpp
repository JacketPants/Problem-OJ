#include <cmath>
#include <cstring>
#include <iostream>
#define MAXN 100010
using namespace std;
int isPrime(long long n)
{
    double n_sqrt;
    if (n == 2 || n == 3)
        return 1;
    if (n % 6 != 1 && n % 6 != 5)
        return 0;
    n_sqrt = floor(sqrt((float)n));
    for (int i = 5; i <= n_sqrt; i += 6)
    {
        if (n % (i) == 0 | n % (i + 2) == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n, m, cnt = 0, sum = 0;
    cin >> n >> m;
    for (long long i = 2;; i++)
    {
        if (isPrime(i))
        {
            cnt++;
            if (cnt >= n)
            {
                printf("%lld", i);
                if (++sum == 10)
                {
                    putchar('\n');
                    sum = 0;
                }
                else if (cnt != m)
                    putchar(' ');
                if (cnt == m)
                    break;
            }
        }
    }
    return 0;
}
