#include "math.h"
#include "stdio.h"
int main()
{
    int i, j, k, a[10000];
    for (i = 0; i < 10000; i++)
        a[i] = 1;
    for (i = 0; i < 1000; i++)
        a[i] = 0;
    for (i = 1000; i <= 9999; i++)
    {
        for (j = 2; j <= sqrt(i); j++)
            if (i % j == 0)
            {
                a[i] = 0;
                break;
            }
        k = i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000;
        for (j = 2; j <= sqrt(k); j++)
            if (k % j == 0)
            {
                a[i] = 0;
                break;
            }
    }
    for (i = 0; i <= 9999; i++)
    {
        k = i % 10 * 1000 + i / 10 % 10 * 100 + i / 100 % 10 * 10 + i / 1000;
        if (a[i] && a[k])
            a[k] = 0;
    }
    for (i = 0; i <= 9999; i++)
        if (a[i] == 1)
            printf("%d ", i);
}
