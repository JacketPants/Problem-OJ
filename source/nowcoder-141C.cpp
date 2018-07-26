#include <algorithm>
#include <ext/rope>
#include <iostream>
using namespace std;
using namespace __gnu_cxx;

int main()
{
    int n, m, p, s;
    scanf("%d%d", &n, &m);
    rope<int> l;
    for (int i = 0; i <= n; i++)
        l.push_back(i);
    while (m--)
    {
        scanf("%d%d", &p, &s);
        l = l.substr(0, 1) + l.substr(p, s) + l.substr(1, p - 1) + l.substr(p + s, n);
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", l[i], i == n ? '\n' : ' ');
    return 0;
}
