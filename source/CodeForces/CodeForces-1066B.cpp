#include <algorithm>
#include <iostream>
using namespace std;
int house[1010], cnt[1010] = {0};
int main()
{
    int n, m, tmp, isWarm = 1, ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", house + i);
        if (house[i])
        {
            ans++;
            for (int j = max(0, i - m + 1); j < i + m && j < n; j++)
                cnt[j]++;
        }
    }
    for (int i = 0; i < n; i++)
        if (!cnt[i])
        {
            isWarm = 0;
            break;
        }
    if (isWarm)
    {
        for (int i = 0; i < n; i++)
        {
            if (house[i])
            {
                bool isCancal = true;
                for (int j = max(0, i - m + 1); j < i + m && j < n; j++)
                    if (cnt[j] < 2)
                        isCancal = false;
                if (isCancal)
                {
                    ans--;
                    for (int j = max(0, i - m + 1); j < i + m && j < n; j++)
                        cnt[j]--;
                }
            }
        }
        cout << ans << endl;
    }
    else
        puts("-1");
    return 0;
}