#include <iostream>

using namespace std;
int s[200020], p[200020];
bool vis[200020];
int main()
{
    int n, d, sc, P, Q, ans = 1;
    while (cin >> n >> d)
    {
        d--;
        for (int i = 0; i < n; i++)
            scanf("%d", s + i);
        for (int i = 0; i < n; i++)
            scanf("%d", p + i);
        sc = s[d] + p[0];
        ans = P = vis[0] = true;
        Q = n - 1;
        for (int i = 0; i < n; i++)
        {
            if (i == d)
                continue;
            if (s[i] + p[Q] <= sc)
            {
                vis[Q--] = true;
            }
            else
            {
                vis[P++] = true;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
5 4
14 10 9 5 1
7 6 5 4 1
*/