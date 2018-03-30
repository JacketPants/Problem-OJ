#include <iostream>
using namespace std;
long long ans[100];
int main()
{
    int t, a, b;
    scanf("%d", &t);
    ans[0] = ans[1] = 1LL;
    for (int i = 2; i < 50; i++)
        ans[i] = ans[i - 1] + ans[i - 2];
    while (t--)
    {
        scanf("%d%d", &a, &b);
        cout << ans[a - b] << endl;
    }
    return 0;
}