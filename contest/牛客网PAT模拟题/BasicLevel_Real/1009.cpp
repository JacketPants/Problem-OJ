#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int vn[4], va[4], vb[4];
int toNum(int *num)
{
    return num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
}
void toDig(int n, int *num)
{
    for (int i = 3; i >= 0; i--)
    {
        num[i] = n % 10;
        n /= 10;
    }
}
void copy(int *a, int *b, int n)
{
    for (int i = 0; i < n; i++)
        a[i] = b[i];
}
bool cmpup(int a, int b)
{
    return a < b;
}
bool cmpdown(int a, int b)
{
    return a > b;
}
int main()
{
    int n, a, b;
    while (cin >> n)
    // for (int i = 1; i < 10000; i++)
    {
        // if (i % 1111 == 0)
        //     continue;
        // n = i;
        // printf("%d\n", i);
        do
        {
            toDig(n, vn);
            copy(va, vn, 4);
            copy(vb, vn, 4);
            sort(va, va + 4, cmpup);
            sort(vb, vb + 4, cmpdown);
            a = toNum(va);
            b = toNum(vb);
            n = b - a;
            printf("%04d - %04d = %04d\n", b, a, n);
        } while (n != 6174);
    }
    return 0;
}
