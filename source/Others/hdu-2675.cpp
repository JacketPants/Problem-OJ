#include <cmath>
#include <iostream>
#define INF 0x3f3f
#define EPS 1e-15
using namespace std;
const double e = exp(1);
double Func(double x)
{
    return log(x) / x;
}
double Find(double l, double r, double x, double (*func)(double), bool isUp = true)
{
    double ans = 0, m, y;
    while (l <= r && ans == 0)
    {
        m = (l + r) / 2;
        y = func(m);
        if (fabs(x - y) < EPS)
            ans = m;
        else if (x < y)
        {
            if (isUp)
                r = m;
            else
                l = m;
        }
        else
        {
            if (isUp)
                l = m;
            else
                r = m;
        }
    }
    return ans;
}
int main()
{
    double y, left, ans1, ans2;
    while (~scanf("%lf", &y))
    {
        left = (1.0 + log(y)) / (e * y);
        if (left > 1.0 / e)
        {
            puts("Happy to Women�s day!\n");
            continue;
        }
        if (y == 1)
        {
            puts("2.71828");
            continue;
        }
        ans1 = Find(0, e, left, Func, true);
        ans2 = Find(e, INF, left, Func, false);
        printf("%.5lf %.5lf\n", ans1, ans2);
    }
    return 0;
}

/*
a=x, b=ey
a^b=b^a
a*log_(a)^(b)=b
a*ln(b)/ln(a)=b
a/ln(a)=b/ln(b)
x/ln(x)=ey/(1+ln(y))
ln(x)/x=(1+ln(y))/ey
*/
/*
1
2
3
4
5
6
7
8
9
10
1234
*/
