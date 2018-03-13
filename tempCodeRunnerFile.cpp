#include<iostream>
#include<cstring>

#define MAXN 1000
using namespace std;
struct MyMatrix
{
    int n, m;
    int a[MAXN][MAXN];
    void clear()
    {
        n = m = 0;
        memset(a, 0, sizeof a);
    }
    MyMatrix operator*(const MyMatrix &x) const
    {
        MyMatrix tem;
        tem.clear();
        tem.n = n;
        tem.m = m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < x.m; j++)
                for (int k = 0; k < m; k++)
                    tem.a[i][j] = a[i][k] * x.a[k][j];
        return tem;
    }
};



int main()
{
    MyMatrix a;
    a.n=a.m = 10;
    int n = 16;
    cout << int(n&1) << endl;
    return 0;
}