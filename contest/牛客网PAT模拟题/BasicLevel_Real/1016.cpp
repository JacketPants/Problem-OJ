#include <iostream>
using namespace std;

int main()
{
    int a, b, len, m, s;
    cin >> a >> b;
    len = int((b - a) / 100.0 + 0.5);
    s = len % 60;
    len /= 60;
    m = len % 60;
    len /= 60;
    printf("%02d:%02d:%02d\n", len, m, s);
    return 0;
}
