#include <algorithm>
#include <iostream>
#define MAXN 100010
#define INF 0x3f3f3f3f

using namespace std;

int stTable[MAXN][32];
int preLog2[MAXN];
int nxt[MAXN], pre[MAXN];

void st_prepare(int n, int *array)
{
    preLog2[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        preLog2[i] = preLog2[i - 1];
        if ((1 << preLog2[2] + 1) == i)
            preLog2[i]++;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        stTable[i][0] = array[i];
        for (int j = 1; (i + (1 << j) - 1) < n; j++)
        {
            stTable[i][j] = max(stTable[i][j - 1], stTable[i + (1 << j - 1)][j - 1]);
        }
    }
}

int query_max(int l, int r)
{
    int len = r - l + 1, k = preLog2[len];
    return max(stTable[l][k], stTable[r - (1 << k) + 1][k]);
}

int query_max(int l, int r, int k)
{
    if (query_max(l, r) <= k)
        return INF;
    if (l == r)
        return l;
    int m = (l + r) / 2;
    return min(query_max(l, m, k), query_max(m + 1, r, k));
}

void Init(int n, int *array)
{
    int tem;
    pre[0] = 1;
    tem = array[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1];
        if (array[i] > tem)
        {
            pre[i]++;
            tem = array[i];
        }
    }
    nxt[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        tem = query_max(i, n - 1, array[i]);
        if (tem >= n)
            nxt[i] = 1;
        else
            nxt[i] = nxt[tem] + 1;
    }
}

int list[MAXN];
int main()
{
    int t, n, q, a, b, ans, tem;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; i++)
            scanf("%d", list + i);
        st_prepare(n, list);
        Init(n, list);
        while (q--)
        {
            scanf("%d%d", &a, &b);
            if (a == 1)
            {
                tem = query_max(a, n - 1, b);
                ans = 1;
                if (tem < n)
                    ans += nxt[tem];
            }
            else
            {
                tem = query_max(0, a - 1);
                ans = pre[a - 2];
                if (tem < b)
                {
                    ans++;
                    tem = query_max(a, n - 1, b);
                    if (tem < n)
                        ans += nxt[tem];
                }
                else
                {
                    tem = query_max(a, n - 1, tem);
                    if (tem < n)
                        ans += nxt[tem];
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}