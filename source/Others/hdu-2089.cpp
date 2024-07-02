#include <iostream>
#define MAXN 1000000
using namespace std;

int a[MAXN];
int num[7] = {0};
int main()
{
    int n, m, flag;
    for (int i = 1; i < MAXN; i++)
    {
        flag = 1;
        num[0]++;
        for (int j = 0; j < 7; j++)
            if (num[j] == 10)
                num[j] = 0, num[j + 1]++;
        for (int j = 0; j < 7; j++)
            if (num[j] == 4 || (num[j] == 2 && num[j + 1] == 6))
                flag = 0;
        a[i] = a[i - 1] + flag;
    }
    while (scanf("%d%d", &n, &m), n, m)
        printf("%d\n", a[m] - a[n - 1]);
    return 0;
}