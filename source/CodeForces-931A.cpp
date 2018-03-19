#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    double len;
    while (~scanf("%d%d", &a, &b))
    {
        len = abs(a - b) / 2.0;
        cout << floor(len) * (floor(len) + 1) + (floor(len) == ceil(len) ? 0 : ceil(len)) << endl;
    }
    return 0;
}