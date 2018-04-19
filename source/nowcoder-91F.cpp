#include <iostream>
using namespace std;
long long list[64];
long long f[64];
int Check(long long n)
{
    for (int i = 1; i <= 60; i++)
        if (n == f[i])
            return i;
    return false;
}
int main()
{
    f[0] = 1LL;
    f[1] = 1LL;
    for (int i = 2; i <= 60; i++)
        f[i] = f[i - 1] + f[i - 2];
    for (int i = 1; i <= 60; i++)
        list[i] = 1LL << (i - 1);
    int t, i;
    long long n, out;
    scanf("%d", &t);
    while (t--)
    {
        out = 0LL;
        cin >> n;
        i = 60;
        do
        {
            while (f[i] > n)
                i--;
            n -= f[i];
            out += list[i];
        } while (n && !Check(n));
        if (n)
            out += list[Check(n)];
        cout << out << endl;
    }
    return 0;
}