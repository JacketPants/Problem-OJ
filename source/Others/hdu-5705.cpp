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
        // 转化为秒数
        s = ss + mm * 60 + hh * 3600;
        // 乘120以便于整数处理
        a *= 120;
        do
            s++;
        // 每过1秒，时针走1°，分针走12°
        while (abs(abs((s * 12) % MOD - s % MOD) - a) > 10);
        printf("Case #%d: %0.2d:%0.2d:%0.2d\n", t++, (s / 3600) % 12, (s / 60) % 60, s % 60);
    }
    return 0;
}