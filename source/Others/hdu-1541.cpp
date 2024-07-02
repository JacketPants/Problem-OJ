#include <cstdio>
#include <cstring>
#include <iostream>
#define lowbit(x) x & -x
#define MAXN 35000
using namespace std;

int Tree[MAXN];
int ans[MAXN];

void add(int x, int value)
{
    for (int i = x; i <= MAXN; i += lowbit(i))
        Tree[i] += value;
}

int get(int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += Tree[i];
    return sum;
}

int main()
{
    int x, y, n;
    while (~scanf("%d", &n))
    {
        memset(Tree, 0, sizeof Tree);
        memset(ans, 0, sizeof ans);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &x, &y);
            ans[get(x + 1)]++;
            add(x + 1, 1);
        }
        for (int i = 0; i < n; i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}