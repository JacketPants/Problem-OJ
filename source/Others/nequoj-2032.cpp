#include <algorithm>
#include <iostream>

using namespace std;
int a[200010];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    sort(a, a + n);
    if (k > n || k < 0)
        puts("-1");
    else if (k)
        printf("%d\n", a[k - 1]);
    else if (a[0] == 1)
        puts("-1");
    else
        puts("1");
    // if (k > 0 && k < n)
    // {
    //     nth_element(a, a + k - 1, a + n);
    //     printf("%d\n", a[k - 1]);
    // }
    // else if (k == 0)
    // {
    //     if (*min_element(a, a + n) == 1)
    //         puts("-1");
    //     else
    //         puts("1");
    // }
    // else
    // {
    //     puts("-1");
    // }
    return 0;
}