#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct Point
{
    int x, y, z;
    Point(int a, int b, int c)
    {
        x = a;
        y = b;
        z = c;
    }
    Point()
    {
        x = 0;
        y = 0;
        z = 0;
    }
};
int step[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};
bool p[12][12];
int main()
{
    char a[10], b[10];
    while (~scanf("%s%s", a, b))
    {
        Point tem;
        memset(p, 0, sizeof p);
        for (int i = 2; i < 10; i++)
            for (int j = 2; j < 10; j++)
                p[i][j] = true;

        tem.x = a[0] - 'a' + 2;
        tem.y = a[1] - '0' + 1;
        queue<Point> q;
        q.push(tem);
        while (!q.empty())
        {
            // for (int i = 2; i < 10; i++)
            // {
                // for (int j = 2; j < 10; j++)
                    // cout << p[i][j];
                // cout << endl;
            // }
            tem = q.front();
            q.pop();
            if (tem.x == b[0] - 'a' + 2 && tem.y == b[1] - '0' + 1)
                break;
            p[tem.x][tem.y] = false;
            for (int i = 0; i < 8; i++)
                if (p[tem.x + step[i][0]][tem.y + step[i][1]])
                    q.push(Point(tem.x + step[i][0], tem.y + step[i][1], tem.z + 1));
        }
        printf("To get from %s to %s takes %d knight moves.\n", a, b, tem.z);
    }
    return 0;
}
/*
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6
*/