#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
int num[101];
int getNum(int n, int l)
{
    int ans = 0;
    int base = 1;
    for (int i = n + l - 1; i >= n; i--)
    {
        ans += base * num[i];
        base *= 10;
    }
    return ans;
}
int isPrime(int n)
{ //返回1表示判断为质数，0为非质数，在此没有进行输入异常检测
    float n_sqrt;
    if (n == 2 || n == 3)
        return 1;
    if (n % 6 != 1 && n % 6 != 5)
        return 0;
    n_sqrt = floor(sqrt((float)n));
    for (int i = 5; i <= n_sqrt; i += 6)
    {
        if (n % (i) == 0 | n % (i + 2) == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int n, l, m;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
        scanf("%d", num + i);
    set<int> ans;
    for (int i = 0; i + l - 1 < n; i++)
    {
        if (num[i] == 0)
            continue;
        m = getNum(i, l);
        if (isPrime(m))
            ans.insert(m);
    }
    bool flag = false;
    for (auto &th : ans)
    {
        if (flag)
            putchar(',');
        printf("%d", th);
        flag = true;
    }
    puts("");
    return 0;
}
