#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool list[100010];
void getPrime()
{
    for (int i = 2; i < 100010; i++)
    {
        if (list[i])
        {
            for (int j = i * 2; j < 100010; j += i)
                list[j] = false;
        }
    }
}
int main()
{
    memset(list, 1, sizeof list);
    getPrime();
    int n;
    cin >> n;
    if (n < 3)
        cout << 1 << endl;
    else
        cout << 2 << endl;
    n++;
    for (int i = 2; i <= n; i++)
        if (list[i])
            printf("1 ");
        else
            printf("2 ");
    putchar('\n');
    return 0;
}
