#include <cmath>
#include <iostream>
#include <map>
using namespace std;
map<int, int> list;
int s[101];

int main()
{
    for (int i = 0; i <= 100; i++)
        s[i] = i * i;
    int a, b, c, d, ans;
    while (~scanf("%d%d%d%d", &a, &b, &c, &d))
    {
        if ((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))
        {
            puts("0");
            continue;
        }
        list.clear();
        ans = 0;
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                list[a * s[i] + b * s[j]]++;
            }
        }
        for (int i = 1; i <= 100; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                ans += list[-c * s[i] + -d * s[j]];
            }
        }
        printf("%d\n", ans * 16);
    }
    return 0;
}