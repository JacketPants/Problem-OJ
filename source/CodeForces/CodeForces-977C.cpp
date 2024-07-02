#include <algorithm>
#include <iostream>
#define INF 1000000001
using namespace std;
int list[200005];
int main()
{
    int n, k;
    cin >> n >> k;
    list[0] = INF;
    for (int i = 1; i <= n; i++)
        scanf("%d", list + i);
    sort(list, list + n + 1);
    if (k == 0)
    {
        if (list[0] == 1)
            cout << -1 << endl;
        else
            cout << list[0] - 1 << endl;
    }
    else if (list[k - 1] == list[k])
        cout << -1 << endl;
    else
    {
        cout << list[k] - 1 << endl;
    }
    return 0;
}