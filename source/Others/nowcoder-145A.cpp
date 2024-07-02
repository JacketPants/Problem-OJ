#include <bitset>
#include <cmath>
#include <iostream>

using namespace std;

bool bits[32];
int pow2[30];
int ans[500005];
int main()
{
    int n, p, len, tem = 1;
    for (int i = 0; i < 30; i++)
    {
        pow2[i] = tem;
        tem <<= 1;
    }
    cin >> n;
    len = log2(n);
    for (int i = n - 1; i >= 0; i--)
    {
        tem = i;
        p = 0;
        while (tem)
        {
            bits[p++] = !(bool)(tem % 2);
            tem /= 2;
        }
        tem = 0;
        while (p)
        {
            if (bits[--p])
                tem += pow2[p];
        }
        ans[i] = tem;
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
    return 0;
}