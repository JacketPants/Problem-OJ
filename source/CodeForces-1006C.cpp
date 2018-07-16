#include <algorithm>
#include <iostream>

using namespace std;
int list[200001];
long long p[200001];
int main()
{
    int n, a, b;
    long long sum = 0, ans = 0;
    p[0] = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", list + i);
        p[i] = p[i - 1] + list[i];
    }
    sum = p[n];
    a = 1;
    b = n;
    while (p[a] <= sum / 2.0)
        a++;
    a--;
    while (sum - p[b] <= p[a])
        b--;
    while (p[a] != sum - p[b])
    {
        if (p[a] > sum - p[b])
            a--;
        else
            b++;
        ans = p[a];
    }
    cout << ans << endl;
    return 0;
}
