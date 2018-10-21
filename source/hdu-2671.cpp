#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int t, ax, ay, bx, by, cx, cy;
    double k, b;
    cin >> t;
    while (t--)
    {
        scanf("%lf%d%d%d%d%d%d", &k, &ax, &ay, &bx, &by, &cx, &cy);
        b = cy - k * cx;
        if ((ax * k + b > ay && bx * k + b > by) || (ax * k + b < ay && bx * k + b < by))
        {
        }
        else
        {
            
        }
    }
    return 0;
}