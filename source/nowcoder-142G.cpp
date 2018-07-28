#include <iostream>
#include <map>
#include <set>
using namespace std;
set<int> s;
map<int, int> l;
template <class T>
inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if (c = getchar(), c == EOF)
        return 0;
    while (c != '-' && (c < '0' || c > '9'))
        c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9')
        ret = ret * 10 + (c - '0');
    ret *= sgn;
    return 1;
}
int main()
{
    int t, n, m, tem;
    cin >> t;
    while (t--)
    {
        s.clear();
        l.clear();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scan_d(tem);
            s.insert(tem);
            l[tem]++;
        }
        for (set<int>::reverse_iterator i = s.rbegin(); i != s.rend(); i++)
        {
            cout << *i << endl;
        }
    }
    return 0;
}