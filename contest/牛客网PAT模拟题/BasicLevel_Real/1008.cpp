#include <algorithm>
#include <iostream>
using namespace std;
int table[3][3] = {
    {1, 0, 2},
    {2, 1, 0},
    {0, 2, 1}};
int To(char ch)
{
    if (ch == 'C')
        return 0;
    else if (ch == 'J')
        return 1;
    return 2;
}
int main()
{
    int n;
    char a, b;
    int score[3] = {0}, cnta[3] = {0}, cntb[3] = {0};
    cin >> n;
    while (n--)
    {
        cin >> a >> b;
        score[table[To(a)][To(b)]]++;
        if (table[To(a)][To(b)] == 0)
            cnta[To(a)]++;
        else if (table[To(a)][To(b)] == 2)
            cntb[To(b)]++;
    }
    cout << score[0] << ' ' << score[1] << ' ' << score[2] << endl;
    cout << score[2] << ' ' << score[1] << ' ' << score[0] << endl;
    if (cnta[2] >= cnta[1] && cnta[2] >= cnta[0])
        putchar('B');
    else if (cnta[0] >= cnta[1] && cnta[0] >= cnta[2])
        putchar('C');
    else
        putchar('J');
    putchar(' ');
    if (cntb[2] >= cntb[1] && cntb[2] >= cntb[0])
        putchar('B');
    else if (cntb[0] >= cntb[1] && cntb[0] >= cntb[2])
        putchar('C');
    else
        putchar('J');
    putchar('\n');
    return 0;
}