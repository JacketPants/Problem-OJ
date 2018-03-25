#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
// p为图像存储空间
// l为数字存储空间
bool p[65][65];
vector<int> l;
//图像到数字函数
void ptol(int x, int y, int a, int b, int w = 0)
{
    // 判断白与黑是否出现过，即当前区域是否纯黑或纯白
    bool isBlack = false, isWhite = false;
    for (int i = x; i < y; i++)
        for (int j = a; j < b; j++)
            if (p[i][j])
                isBlack = true;
            else if (!p[i][j])
                isWhite = true;
    // 当前区域纯黑
    if (isBlack && !isWhite)
        l.push_back(w);
    // 当前区域不纯白也不纯黑
    else if (isBlack && isWhite)
    {
        // 为方便记录数字，这里的w最终结果是翻转的
        w *= 10;
        ptol(x, x + (y - x) / 2, a, a + (b - a) / 2, w + 1);
        ptol(x, x + (y - x) / 2, a + (b - a) / 2, b, w + 2);
        ptol(x + (y - x) / 2, y, a, a + (b - a) / 2, w + 3);
        ptol(x + (y - x) / 2, y, a + (b - a) / 2, b, w + 4);
    }
    // 纯白时无需操作，进行剪枝
}
// 数字到图像函数
void ltop(int n)
{
    // x,y为纵轴的始末点
    // a,b为横轴的始末点
    int x, y, a, b;
    memset(p, 0, sizeof p);
    for (int k = 0; k < l.size(); k++)
    {
        x = a = 0;
        y = b = n;
        // 根据数字确定涂黑位置
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
        // 涂黑操作
        for (int i = x; i < y; i++)
            for (int j = a; j < b; j++)
                p[i][j] = true;
    }
}
// 整数翻转函数
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
        // 保证只有样例之间有空行
        if (t)
            putchar('\n');
        printf("Image %d\n", ++t);
        // 初始化vector容器
        l.clear();
        //如果是正数，则为图像转数字
        if (n > 0)
        {
            // 去除缓存区回车
            getchar();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    p[i][j] = (bool)(getchar() - '0');
                getchar();
            }
            ptol(0, n, 0, n);
            // 防止当纯白时，多输出空行问题
            if (l.size())
            {
                // 五进制转十进制
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
                // 输出答案，注意每十二个数字需要输一次回车
                for (int i = 0; i < l.size(); i++)
                {
                    if (i % 12)
                        putchar(' ');
                    printf("%d", l[i]);
                    // 第二个条件用于防止数字有12的倍数个时多输出一个回车
                    if (i % 12 == 11 && i != l.size() - 1)
                        putchar('\n');
                }
                putchar('\n');
            }
            printf("Total number of black nodes = %d\n", l.size());
        }
        // 如果是负数，则数字转图像
        else
        {
            n = -n;
            while (~scanf("%d", &tem) && tem != -1)
            {
                // 十进制转五进制
                tema = 0;
                for (int i = 1; tem; i *= 10)
                {
                    tema += (tem % 5) * i;
                    tem /= 5;
                }
                // 压入数组
                l.push_back(tema);
            }
            ltop(n);
            // 输出图像
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