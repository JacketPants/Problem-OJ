#include <algorithm>
#include <iostream>
using namespace std;
int list[10000];
int main()
{
    int n, a[5] = {0}, cnt = 0;
    scanf("%d", &n);
    bool flag[6] = {false};
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    for (int i = 0; i < n; i++)
    {
        if (!(list[i] % 10))
        {
            flag[0] = true;
            a[0] += list[i];
        }
        else if (list[i] % 5 == 1)
        {
            flag[1] = true;
            if (flag[5])
                a[1] -= list[i];
            else
                a[1] += list[i];
            flag[5] = !flag[5];
        }
        else if (list[i] % 5 == 2)
        {
            flag[2] = true;
            a[2]++;
        }
        else if (list[i] % 5 == 3)
        {
            flag[3] = true;
            a[3] += list[i];
            cnt++;
        }
        else if (list[i] % 5 == 4)
        {
            flag[4] = true;
            a[4] = max(a[4], list[i]);
        }
    }
    if (flag[0])
        printf("%d ", a[0]);
    else
        printf("N ");
    if (flag[1])
        printf("%d ", a[1]);
    else
        printf("N ");
    if (flag[2])
        printf("%d ", a[2]);
    else
        printf("N ");
    if (flag[3])
        printf("%.1f ", double(a[3]) / cnt);
    else
        printf("N ");
    if (flag[4])
        printf("%d\n", a[4]);
    else
        printf("N\n");
    return 0;
}
