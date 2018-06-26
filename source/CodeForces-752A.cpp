#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a, b, n;
    double m;
    while (cin >> a >> b >> n)
    {
        m = ceil(n / 2.0);
        printf("%d %d %c\n", (int)(ceil(m / b)), ((int)m) % b ? ((int)m) % b : b, n % 2 ? 'L' : 'R');
    }
    return 0;
}