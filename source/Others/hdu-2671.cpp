#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int t, ax, ay, bx, by, cx, cy;
    double k, b, ans;
    cin >> t;
    while (t--)
    {
        scanf("%lf%d%d%d%d%d%d", &k, &ax, &ay, &bx, &by, &cx, &cy);
        b = cy - k * cx;
        if ((ax * k + b > ay && bx * k + b > by) || (ax * k + b < ay && bx * k + b < by))
        {
            double x = ax - (2 * k * ((k * ax - ay + b) / (k * k + 1)));
            double y = ay - (2 * (-1) * ((k * ax - ay + b) / (k * k + 1)));
            ans = sqrt((x - bx) * (x - bx) + (y - by) * (y - by));
        }
        else
        {
            ans = sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}