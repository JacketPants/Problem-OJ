#include <iostream>
#include <unordered_set>

using namespace std;
int main()
{
    int n, m, a, b;
    while (~scanf("%d%d", &n, &m))
    {
        unordered_set<int> setx, sety;
        int ans = 2 * n - n % 2;
        while (m--)
        {
            scanf("%d%d", &a, &b);
            setx.insert(a);
            sety.insert(b);
        }
        if (n % 2 && (setx.count(n / 2 + 1) || sety.count(n / 2 + 1)))
            ans++;
        printf("%d\n", ans - setx.size() - sety.size());
    }
    return 0;
}
