#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    int now, last;
    string s, ans;
    while (getline(cin, s))
    {
        now = 1;
        last = 0;
        ans.clear();
        for (auto &ch : s)
        {
            if (ch < 'A' || ch > 'Z')
            {
                ans.push_back(ch);
                continue;
            }
            ch += now;
            if (ch > 'Z')
                ch -= 26;
            ans.push_back(ch);
            last += now;
            last %= 26;
            swap(now, last);
        }
        cout << ans << endl;
    }
    return 0;
}
