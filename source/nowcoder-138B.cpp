#include <algorithm>
#include <iostream>
using namespace std;

int main()
{
    int n, m, k, a, b, ans, tem = -0x3f3f3f3f;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d%d", &a, &b);
        if (tem <= a * m + b * (n - m))
        {
            ans = i;
            tem = a * m + b * (n - m);
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (i)
            putchar(' ');
        if (i == ans)
            printf("%d", n);
        else
            putchar('0');
    }
    putchar('\n');
    return 0;
}