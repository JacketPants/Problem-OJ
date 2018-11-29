#include <algorithm>
#include <iostream>
using namespace std;
struct Bing
{
    int n, p;
    bool operator<(const Bing &n) &
    {
        return (double)this->p / this->n > (double)n.p / n.n;
    }
} list[1001];
int main()
{
    int n, m;
    double ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i].n);
    for (int i = 0; i < n; i++)
        scanf("%d", &list[i].p);
    sort(list, list + n);
    for (int i = 0; i < n && m; i++)
    {
        if (m - list[i].n >= 0)
        {
            ans += list[i].p;
            m -= list[i].n;
        }
        else
        {
            ans += m * (double)list[i].p / list[i].n;
            m = 0;
        }
    }
    printf("%.2lf\n", ans);
    return 0;
}