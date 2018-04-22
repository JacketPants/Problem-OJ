#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    double list[3];
    while (cin >> a >> b >> c)
    {
        list[0] = 180.0 - a;
        list[1] = 180.0 - b;
        list[2] = 180.0 - list[0] - list[1];
        sort(list, list + 3);
        if (a + b + c == 360)
            printf("%0.4lf %0.4lf %0.4lf\n", list[0], list[1], list[2]);
        else
            printf("-1 -1 -1\n");
    }
    return 0;
}