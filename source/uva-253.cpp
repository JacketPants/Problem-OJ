#include <iostream>
using namespace std;
int main()
{
    char s[20];
    int ans;
    while (~scanf("%s", s))
    {
        ans = 0;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (s[i] && ((s[i] == s[6 + j] && s[5 - i] == s[11 - j]) || (s[i] == s[11 - j] && s[5 - i] == s[6 + j])))
                {
                    ans++;
                    s[i] = s[5 - i] = s[6 + j] = s[11 - j] = 0;
                }
            }
        }
        if (ans == 3)
            puts("TRUE");
        else
            puts("FALSE");
    }
    return 0;
}