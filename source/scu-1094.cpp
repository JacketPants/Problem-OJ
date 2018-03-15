#include <algorithm>
#include <iostream>
using namespace std;
struct Point
{
    int x, y;
};
bool cmp(const Point &a, const Point &b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}
int main()
{
    int n, x, y, ans;
    Point list[100000];
    while (~scanf("%d", &n) && n)
    {
        ans = 1;
        for (int i = 0; i < n; i++)
            scanf("%d%d", &list[i].x, &list[i].y);
        sort(list, list + n);
        for (int i = 0; i < n; i++)
        {
            y = list[i].y + 2;
            x = list[i].x;
            for (int j = i; j < n; j++)
            {
                if (list[j].x > x && y == list[j].y)
                {
                    
                }
            }
        }
    }
    return 0;
}