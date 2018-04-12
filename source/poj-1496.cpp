#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int st[30][30];
void Init()
{
    memset(st, 0, sizeof st);
    for (int i = 0; i <= 26; i++)
        for (int j = 0; j <= 26; j++)
            if (!j || i == j)
                st[i][j] = 1;
            else
                st[i][j] = st[i - 1][j - 1] + st[i - 1][j];
    st[0][0] = 0;
}
int main()
{
    Init();
    string s;
    while (cin >> s)
    {
        bool flag = false;
        for (int i = 1; i < s.length() && !flag; i++)
            if (s[i] <= s[i - 1])
                flag = true;
        if (!flag)
        {
        }
    }
    return 0;
}