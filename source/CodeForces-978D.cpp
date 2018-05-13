#include <iostream>

using namespace std;
int list[100001];
int s[100001];
int main()
{
    int n, m;
    long long sum = 0;
    cin >> n;
    m = n - 1;
    for (int i = 0; i < n; i++)
        cin >> list[i];
    for (int i = 0; i < m; i++)
    {
        s[i] = s[i + 1] - s[i];
        sum += s[i];
    }
    if (!(sum % m == 0 || (sum + 1) % m == 0 || (sum - 1) % m == 0))
        puts("-1");
    else
    {

    }
    return 0;
}