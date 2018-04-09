#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;
const double PI = asin(1) * 2;
double list[100010];
int n, f;
double Search(double a, double b)
{
    if (a - b < 0.000001)
        return a;
    double m = (a + b) / 2.0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += int(list[i] / m);
    if (cnt < f)
        return Search(m, b);
    return Search(a, m);
}
int main()
{
    int t, tem;
    double a = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &f);
        f++;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tem);
            list[i] = tem * tem * PI;
            a = max(a, list[i]);
        }
        cout << fixed << setprecision(4) << Search(a, 0) << endl;
    }
    return 0;
}