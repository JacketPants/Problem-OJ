#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int t, n, list[1000], k;
    scanf("%d", &t);
    while (t--)
    {
        k = 0;
        scanf("%d", &n);
        if(n<0)
        {
            n = -n;
            putchar('-');
        }
        while (n)
        {
            list[k++] = n % 6;
            n /= 6;
        }
        if (k)
            for (int i = k - 1; i >= 0; i--)
                putchar('0' + list[i]);
        else
            putchar('0');
        putchar('\n');
    }
    return 0;
}