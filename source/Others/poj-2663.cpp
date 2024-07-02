#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int n, list[31] = {0};
    list[0] = 1;
    list[2] = 3;
    for (int i = 4; i <= 30; i++)
        list[i] = 4 * list[i - 2] - list[i - 4];
    while (~scanf("%d", &n) && n >= 0)
        printf("%d\n", list[n]);
    return 0;
}