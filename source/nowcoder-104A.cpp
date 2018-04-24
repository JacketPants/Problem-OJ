#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
    double a, b, c;
    double list[3];
    while (cin >> a >> b >> c)
    {
        list[0] = a - 60.0;
        list[1] = b - 60.0;
        list[2] = 180.0 - list[0] - list[1];
        sort(list, list + 3);
        printf("%0.4lf %0.4lf %0.4lf\n", list[0], list[1], list[2]);
    }
    return 0;
}