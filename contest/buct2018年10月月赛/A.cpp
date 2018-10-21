#include <iostream>
using namespace std;
int main()
{
    unsigned long long n;
    cin >> n;
    cout << n * n << endl
         << 3 * (n * (1 + n) / 2) << endl;
    return 0;
}