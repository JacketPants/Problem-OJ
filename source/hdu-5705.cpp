#include <cmath>
#include <iostream>
#define MOD 43200
using namespace std;

int main()
{
    int hh, mm, ss, a, s, t = 1;
    while (~scanf("%d:%d:%d", &hh, &mm, &ss))
    {
        scanf("%d", &a);
        s = ss + mm * 60 + hh * 3600;
        a *= 120;
        do
            s++;
        while (abs(abs((s * 12) % MOD - s % MOD) - a) > 10);
        printf("Case #%d: %0.2d:%0.2d:%0.2d\n", t++, (s / 3600) % 12, (s / 60) % 60, s % 60);
    }
    return 0;
}