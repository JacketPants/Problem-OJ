#include <iostream>

using namespace std;

int main()
{
    double sum = 1, ans = 0;
    for (int i = 1; i <= 30; i++)
    {
        sum = sum * i;
        ans = ans + sum;
    }
    printf("%.2e\n", ans);
    return 0;
}