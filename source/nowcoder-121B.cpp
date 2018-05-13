#include <iostream>

using namespace std;
int list[100];
int b[100];
int main()
{
    double ans = 0, m;
    int n;
    cin >> m >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    for (int i = 0; i < n; i++)
        scanf("%d", b + i);
    for (int i = 0; i < n; i++)
    {
        ans += list[i] / m;
    }
    printf("%.2lf\n", ans);
    return 0;
}
/*
10
6
1 1 4 5 1 4 
10 9 8 7 6 5
*/