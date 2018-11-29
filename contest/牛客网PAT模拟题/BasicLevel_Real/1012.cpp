#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
string gao(int n, int d)
{
    string ans;
    while (n)
    {
        ans += char('0' + n % d);
        n /= d;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int a, b, d;
    cin >> a >> b >> d;
    cout << gao(a + b, d) << endl;
    return 0;
}
