#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
bool p[65][65];
vector<int> l;
void ptol(int x, int y, int a, int b, int w = 0)
{
    bool isBlack = false, isWhite = false;
    for (int i = x; i < y; i++)
        for (int j = a; j < b; j++)
            if (p[i][j])
                isBlack = true;
            else if (!p[i][j])
                isWhite = true;
    if (isBlack && !isWhite)
        l.push_back(w);
    else if (isBlack && isWhite)
    {
        w *= 10;
        ptol(x, x + (y - x) / 2, a, a + (b - a) / 2, w + 1);
        ptol(x, x + (y - x) / 2, a + (b - a) / 2, b, w + 2);
        ptol(x + (y - x) / 2, y, a, a + (b - a) / 2, w + 3);
        ptol(x + (y - x) / 2, y, a + (b - a) / 2, b, w + 4);
    }
}
void ltop(int n)
{
    int x, y, a, b;
    memset(p, 0, sizeof p);
    for (int k = 0; k < l.size(); k++)
    {
        x = a = 0;
        y = b = n;
        while (l[k])
        {
            if (l[k] % 10 == 1)
            {
                y = x + (y - x) / 2;
                b = a + (b - a) / 2;
            }
            else if (l[k] % 10 == 2)
            {
                y = x + (y - x) / 2;
                a = a + (b - a) / 2;
            }
            else if (l[k] % 10 == 3)
            {
                x = x + (y - x) / 2;
                b = a + (b - a) / 2;
            }
            else if (l[k] % 10 == 4)
            {
                x = x + (y - x) / 2;
                a = a + (b - a) / 2;
            }
            l[k] /= 10;
        }
        for (int i = x; i < y; i++)
            for (int j = a; j < b; j++)
                p[i][j] = true;
    }
}
int rev(int x)
{
    int i, j;
    for (i = 0, j = x; j; i++)
        j /= 10;
    j = pow(10, i - 1);
    for (i = 0; j; j /= 10)
    {
        i += (x % 10) * j;
        x /= 10;
    }
    return i;
}
int main()
{
    int tem, n, t = 0, tema;
    while (~scanf("%d", &n) && n)
    {
        if (t)
            putchar('\n');
        printf("Image %d\n", ++t);
        l.clear();
        if (n > 0)
        {
            getchar();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    p[i][j] = (bool)(getchar() - '0');
                getchar();
            }
            ptol(0, n, 0, n);
            if (l.size())
            {
                for (int i = 0; i < l.size(); i++)
                {
                    tem = rev(l[i]);
                    tema = 0;
                    for (int i = 1; tem; i *= 5)
                    {
                        tema += (tem % 10) * i;
                        tem /= 10;
                    }
                    l[i] = tema;
                }
                sort(l.begin(), l.end());
                for (int i = 0; i < l.size(); i++)
                {
                    if (i % 12)
                        putchar(' ');
                    printf("%d", l[i]);
                    if (i % 12 == 11 && i != l.size() - 1)
                        putchar('\n');
                }
                putchar('\n');
            }
            printf("Total number of black nodes = %d\n", l.size());
        }
        else
        {
            n = -n;
            while (~scanf("%d", &tem) && tem != -1)
            {
                tema = 0;
                for (int i = 1; tem; i *= 10)
                {
                    tema += (tem % 5) * i;
                    tem /= 5;
                }
                l.push_back(tema);
            }
            ltop(n);
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    if (p[i][j])
                        putchar('*');
                    else
                        putchar('.');
                putchar('\n');
            }
        }
    }
    return 0;
}