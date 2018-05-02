#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int t, n, b;
    bool is;
    int list[100];
    scanf("%d", &t);
    while (t--)
    {
        is = false;
        scanf("%d%d", &n, &b);
        for (int i = 0; i < n; i++)
            scanf("%d", list + i);
        for (int i = 0; i < n; i++)
            list[i] += b;
        for (int i = 0; i < n && !is; i++)
            if (list[i] >= 0 && list[i] % 7 == 0)
                is = true;
        if (is)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}