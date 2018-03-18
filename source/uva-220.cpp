#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char d[10][10], now;
int l[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {-1, 1}, {1, -1}};
bool isLegal(int x, int y)
{
    char g = (now == 'B' ? 'W' : 'B');
    for (int i = 0; i < 8; i++)
    {
        if (d[x + l[i][0]][y + l[i][1]] == g)
        {
            // cout << x << ' ' << y << ':';
            for (int j = 1; d[x + l[i][0] * j][y + l[i][1] * j] != '-'; j++)
            {
                // cout << d[x + l[i][0] * j][y + l[i][1] * j];
                //cout << j;//<< x + l[i][0] * (j + 1) << y + l[i][1] * (j + 1);
                if (d[x + l[i][0] * j][y + l[i][1] * j] == now)
                {
                    return true;
                }
            }
            // cout << endl;
        }
    }
    // cout << false;
    return false;
}
bool Move(int x, int y)
{
    if (d[x][y] != '-')
        return false;
    bool isMove = false;
    char g = (now == 'B' ? 'W' : 'B');
    for (int i = 0; i < 8; i++)
    {
        if (d[x + l[i][0]][y + l[i][1]] == g)
        {
            // cout << x << ' ' << y << ':';
            for (int j = 1; d[x + l[i][0] * j][y + l[i][1] * j] != '-'; j++)
            {
                // cout << d[x + l[i][0] * j][y + l[i][1] * j];
                //cout << j;//<< x + l[i][0] * (j + 1) << y + l[i][1] * (j + 1);
                if (d[x + l[i][0] * j][y + l[i][1] * j] == now)
                {
                    isMove = true;
                    for (int k = j - 1; k; k--)
                    {
                        d[x + l[i][0] * k][y + l[i][1] * k] = now;
                    }
                    break;
                }
            }
            // cout << endl;
        }
    }
    // cout << false;
    if (isMove)
    {
        d[x][y] = now;
        return true;
    }
    now = (now == 'B' ? 'W' : 'B');
    Move(x, y);
    d[x][y] = now;
    return false;
}
int Count(char ch)
{
    int cnt = 0;
    for (int i = 1; i <= 8; i++)
        for (int j = 1; j <= 8; j++)
            if (d[i][j] == ch)
                cnt++;
    return cnt;
}
int main()
{
    char out[100000];
    int t, p = 0;
    char command;
    bool isBlock;
    memset(d, '-', sizeof d);
    scanf("%d", &t);
    while (t--)
    {
        getchar();
        // cout << t << ':' << endl;
        for (int i = 1; i <= 8; i++)
        {
            for (int j = 1; j <= 8; j++)
                d[i][j] = getchar();
            getchar();
        }
        now = getchar();
        // cout << "now:" << now << '\n';
        getchar();
        while (scanf("%c", &command))
        {
            if (command == 'Q')
            {
                for (int i = 1; i <= 8; i++)
                {
                    for (int j = 1; j <= 8; j++)
                        p += sprintf(out + p, "%c", d[i][j]);
                    // fprintf(out, "%c", d[i][j]);
                    // putchar(d[i][j]);
                    p += sprintf(out + p, "\n");
                    // putchar('\n');
                }
                break;
            }
            else if (command == 'L')
            {
                isBlock = false;
                for (int i = 1; i <= 8; i++)
                    for (int j = 1; j <= 8; j++)
                        if (d[i][j] == '-' && isLegal(i, j))
                        {
                            if (isBlock)
                                p += sprintf(out + p, " ");
                            // putchar(' ');
                            isBlock = true;
                            p += sprintf(out + p, "(%d,%d)", i, j);
                        }
                if (!isBlock)
                    p += sprintf(out + p, "No legal move.");
                p += sprintf(out + p, "\n");
                // putchar('\n');
            }
            else if (command == 'M')
            {
                Move(getchar() - '0', getchar() - '0');
                p += sprintf(out + p, "Black - %2d White - %2d\n", Count('B'), Count('W'));
                now = (now == 'B' ? 'W' : 'B');
            }
            getchar();
        }
        if (t)
            p += sprintf(out + p, "\n");
            
        // putchar('\n');
    }
    // cout << out;
    printf("%s", out);
    return 0;
}