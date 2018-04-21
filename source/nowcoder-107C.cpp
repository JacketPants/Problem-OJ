#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int t, n, k, p, m;
    cin >> t;
    while (t--)
    {
        p = 1;
        priority_queue<int> q;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            q.push(m);
        }
        for (int i = 1; i < k; i += ++p);
        for (int i = 0; i < p; i++)
            q.pop();
        printf("%d\n", q.top());
    }
    return 0;
}