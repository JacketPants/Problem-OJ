#include <cstring>
#include <iostream>
using namespace std;

char str[505];

bool Check(int n)
{
    if (n > 0 && (str[n - 1] == '0' && (n < 2 || str[n - 2] == '+' || str[n - 2] == '*')))
        return true;
    return false;
}

bool Check()
{
    int len = strlen(str);
    str[len] = '+';
    if (str[0] == '+' || str[0] == '*')
        return false;
    for (int i = 1; i <= len; i++)
        if ((str[i] == '+' || str[i] == '*') && (str[i - 1] == '+' || str[i - 1] == '*'))
            return false;
    for (int i = 0; i < len; i++)
        if (str[i] == '0' && str[i + 1] <= '9' && str[i + 1] >= '0' && (!i || str[i - 1] == '+' || str[i - 1] == '*'))
            return false;
    str[len] = '\0';
    return true;
}

int main()
{
    int t, len;
    cin >> t;
    while (t--)
    {
        scanf("%s", str);
        len = strlen(str);
        for (int i = 0; i < len; i++)
        {
            if (str[i] == '?')
            {
                if (Check(i))
                    str[i] = '+';
                else
                    str[i] = '1';
            }
        }
        if (Check())
            printf("%s\n", str);
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
/*
100

1

+

0

?

??

???

0?0

1?01

10?0

10?10

01?01

10?01

01?10

0?????????

?????????0

101??01?0

*????1?011

11*11*01????01

?1??1??*01

011+?01+?1?

11+11*??11???1

*/