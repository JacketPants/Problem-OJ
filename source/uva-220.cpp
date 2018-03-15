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
    return isMove;
}
int main()
{
    int t;
    char command;
    bool isBlock;
    memset(d, '-', sizeof d);
    scanf("%d", &t);
    getchar();
    while (t--)
    {
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
                        putchar(d[i][j]);
                    putchar('\n');
                }
                putchar('\n');
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
                                putchar(' ');
                            isBlock = true;
                            printf("(%d,%d)", i, j);
                        }
                if (!isBlock)
                    printf("No legal move.");
                putchar('\n');
            }
            else if (command == 'M')
            {
                
            }
        }
    }
    return 0;
}