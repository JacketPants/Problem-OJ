
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 500010;

int n;
int tmpNum[MAXN], num[MAXN];
int treeNum[MAXN];

int lowbit(int x)
{
    return x & (-x);
}

int getSum(int x)
{
    int sum = 0;
    while (x)
    {
        sum += treeNum[x];
        x -= lowbit(x);
    }
    return sum;
}

void add(int x, int val)
{
    while (x < MAXN)
    {
        treeNum[x] += val;
        x += lowbit(x);
    }
}

long long solve()
{
    long long ans = 0;
    memcpy(tmpNum, num, sizeof(num));
    memset(treeNum, 0, sizeof(treeNum));
    sort(num + 1, num + 1 + n);
    int len = unique(num + 1, num + 1 + n) - (num + 1);
    for (int i = 1; i <= n; i++)
    {
        int id = lower_bound(num + 1, num + 1 + n, tmpNum[i]) - num;
        ans += i - getSum(id) - 1;
        add(id, 1);
    }
    return ans;
}

int main()
{
    int x, y;
    while (~scanf("%d%d%d", &n, &x, &y))
    {
        for (int i = 1; i <= n; i++)
            scanf("%d", &num[i]);
        printf("%lld\n", solve() * min(x, y));
    }
    return 0;
}