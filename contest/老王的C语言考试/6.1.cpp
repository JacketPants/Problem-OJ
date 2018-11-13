#include <iostream>
using namespace std;
int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << GCD(n, m) << ' ' << n * m / GCD(n, m);
    return 0;
}