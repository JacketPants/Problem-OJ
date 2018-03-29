#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
struct V
{
    int x, y, z;
    // bool operator<(const V &x)
    // {
    //     if (this->x == x.x)
    //         return this->y < x.y;
    //     return this->x < x.x;
    // }
};
V list[100];
int dp[100];
int main()
{
    int n, m, a, b, c, t = 1;
    while (~scanf("%d", &n))
    {
        m = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            list[m].x = a;
            list[m].y = b;
            list[m++].z = c;
            list[m].x = b;
            list[m].y = c;
            list[m++].z = a;
            list[m].x = c;
            list[m].y = a;
            list[m++].z = b;
        }
        // sort(list, list + m);
        for (int i = 0; i < m; i++)
            dp[i] = list[i].z;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
                if (list[j].x < list[i].x && list[j].y < list[i].y)
                    dp[i] = max(dp[i], dp[j] + list[i].z);
        }
        printf("Case %d: maximum height = %d", t++, *max_element(dp, dp + m));
    }
    return 0;
}
