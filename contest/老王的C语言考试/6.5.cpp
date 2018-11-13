#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    double ans = 0;
    cin >> a >> b >> c;
    ans = a + 1LL * a * (a - 1) / 2.0;
    for (int i = 1; i <= b; i++)
        ans += i * i;
    for (int i = 1; i <= c; i++)
        ans += 1.0 / i;
    printf("%.2lf", ans);
    return 0;
}
