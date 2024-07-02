#include <cstring>
#include <iostream>
#define MAXN 1000
#define TYPE Matrix
using namespace std;
int m, k;
struct Matrix
{
    int n, m;
    int a[MAXN][MAXN];
    void clear()
    {
        n = m = 0;
        memset(a, 0, sizeof a);
    }
};
Matrix a, tem;
Matrix Mul(Matrix a, Matrix b)
{
    Matrix ans;
    ans.clear();
    ans.n = 6;
    ans.m = 6;
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < m; k++)
                ans.a[i][j] = a.a[i][k] * b.a[k][j] % k;
    return ans;
}
TYPE PowMod(TYPE a, long long i)
{
    TYPE ans;
    ans.m = ans.n = 6;
    ans.a[0][0] = ans.a[1][1] = ans.a[2][2] = ans.a[3][3] = ans.a[4][4] = ans.a[5][5] = 1;
    while (i)
    {
        if (i & 1)
            ans = Mul(ans, a);
        a = Mul(a, a);
        i >>= 1;
    }
    return ans;
}
int main()
{
    while (~scanf("%d%d", &m, &k))
    {
        a.m = tem.m = a.n = tem.n = 6;
        for (int i = 0; i < 6; i++)
            scanf("%d", &tem.a[i][0]);
        for (int i = 0; i < 6; i++)
            for (int j = 0; j < 6; j++)
                a.a[i][j] = 1;
        a.a[0][3] = a.a[1][4] = a.a[2][5] = a.a[3][0] = a.a[4][1] = a.a[5][2];
        a = PowMod(a, m);
        a = Mul(a, tem);
        for (int i = 0; i < 6; i++)
        {
            if (i)
                putchar(' ');
            printf("%d", a.a[i][0]);
        }
        putchar('\n');
    }
    return 0;
}