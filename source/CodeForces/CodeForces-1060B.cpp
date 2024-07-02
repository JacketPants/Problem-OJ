#include <iostream>
int main()
{
    long long n, tmp = 0;
    std::cin >> n;
    while (n >= 9)
    {
        n -= 9;
        tmp += 9;
        tmp += n % 10;
        n /= 10;
    }
    std::cout << tmp + n << std::endl;
    return 0;
}