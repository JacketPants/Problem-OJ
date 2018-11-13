#include <iostream>
int main()
{
    long long n, ans = 0, f = 2;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        ans += f;
        f = f * 10 + 2;
    }
    std::cout << ans;
    return 0;
}