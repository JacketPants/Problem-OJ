#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t, p;
    string s1, s2;
    bool is;
    cin >> t;
    while (t--)
    {
        cin >> s1 >> s2;
        is = false;

        p = s2.length() - 1;
        for (int i = 0; i < s1.length(); i++)
            if (s1[i] == s2[p])
                p--;
        if (p < 0)
            is = true;

        p = s2.length() - 1;
        for (int i = s1.length() - 1; i >= 0; i--)
            if (s1[i] == s2[p])
                p--;
        if (p < 0)
            is = true;

        if(is)
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}