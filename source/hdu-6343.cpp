#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    int t, n, a, b;
    cin >> t;
    while (t--)
    {
        scanf("%d", &n);
        scanf("%d", &a);
        b = a;
        for (int i = 1; i < n; i++)
            scanf("%d", &b);
        printf("%d\n", (int)floor(sqrt(abs(a - b))));
    }
    return 0;
}