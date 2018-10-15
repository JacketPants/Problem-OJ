#include <iostream>

using namespace std;
int list[200005];
int main()
{
    int i, n, m, k, last = 0, cnt = 0;
    cin >> n >> m >> k;
    for (i = 1; i <= n; i++)
        scanf("%d", list + i);
    for (i = n; i; i--)
    {
        if (cnt + list[i] > k)
        {
            m--;
            last = i;
            if(!m)
                break;
            cnt = list[i];
        }
        else
        {
            cnt += list[i];
        }
    }
    if (!i && cnt <= k)
        last = i;
    cout << n - last << endl;
    return 0;
}
