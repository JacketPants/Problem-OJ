#include <iostream>
int main()
{
    long long n, ans = 0, f = 1;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
    	f *= i;
        ans += f;
    }
    std::cout << ans;
    return 0;
}
