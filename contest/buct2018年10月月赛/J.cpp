#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
struct Node
{
    int id;
    int val;
    int mark;
};
Node t[400040];
void Bulid(Node *tree, int *arr, int root, int start, int end)
{
    tree[root].mark = 0;
    if (start == end)
    {
        tree[root].val = arr[start];
        tree[root].id = start;
    }
    else
    {
        int m = (start + end) / 2;
        Bulid(tree, arr, root * 2 + 1, start, m);
        Bulid(tree, arr, root * 2 + 2, m + 1, end);
        if (tree[root * 2 + 1].val < tree[root * 2 + 2].val)
        {
            tree[root].val = tree[root * 2 + 1].val;
            tree[root].id = tree[root * 2 + 1].id;
        }
        else
        {
            tree[root].val = tree[root * 2 + 2].val;
            tree[root].id = tree[root * 2 + 2].id;
        }
    }
}

void PushDown(Node *tree, int root)
{
    if (tree[root].mark)
    {
        tree[root * 2 + 1].mark += tree[root].mark;
        tree[root * 2 + 2].mark += tree[root].mark;
        tree[root * 2 + 1].val += tree[root].mark;
        tree[root * 2 + 2].val += tree[root].mark;
        tree[root].mark = 0;
    }
}

pair<int, int> Query(Node *tree, int root, int start, int end, int qStart, int qEnd)
{
    if (start >= qStart && end <= qEnd)
        return pair<int, int>(tree[root].val, tree[root].id);
    else if (qStart > end || qEnd < start)
        return pair<int, int>(INF, INF);
    PushDown(tree, root);
    int m = (start + end) / 2;
    return min(Query(tree, root * 2 + 1, start, m, qStart, qEnd),
               Query(tree, root * 2 + 2, m + 1, end, qStart, qEnd));
}

void Updata(Node *tree, int root, int start, int end, int uStart, int uEnd, int n)
{
    if (start > uEnd || end < uStart)
        return;
    if (uStart <= start && end <= uEnd)
    {
        tree[root].mark += n;
        tree[root].val += n;
        return;
    }
    PushDown(tree, root);
    int m = (start + end) / 2;
    Updata(tree, root * 2 + 1, start, m, uStart, uEnd, n);
    Updata(tree, root * 2 + 2, m + 1, end, uStart, uEnd, n);
    if (tree[root * 2 + 1].val < tree[root * 2 + 2].val)
    {
        tree[root].val = tree[root * 2 + 1].val;
        tree[root].id = tree[root * 2 + 1].id;
    }
    else
    {
        tree[root].val = tree[root * 2 + 2].val;
        tree[root].id = tree[root * 2 + 2].id;
    }
}
int a[100001], b[100001], c[100001];
inline int lowbit(int x)
{
    return (x & -x);
}

void add(int x, int value)
{
    for (int i = x; i <= 100001; i += lowbit(i))
        c[i] += value;
}

int get(int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += c[i];
    return sum;
}
int main()
{
    int n, q, l, r;
    char op[6];
    pair<int, int> ans;
    while (~scanf("%d%d", &n, &q))
    {
        memset(t, 0, sizeof t);
        memset(c, 0, sizeof c);
        for (int i = 0; i < n; i++)
            scanf("%d", b + i);
        Bulid(t, b, 0, 0, n - 1);
        for (int i = 0; i < q; i++)
        {
            scanf("%s%d%d", op, &l, &r);
            l--;
            r--;
            if (op[0] == 'a')
            {
                Updata(t, 0, 0, n - 1, l, r, -1);
                ans = Query(t, 0, 0, n - 1, l, r);
                while (!ans.first)
                {
                    add(ans.second + 1, 1);
                    Updata(t, 0, 0, n - 1, ans.second, ans.second, b[ans.second]);
                    ans = Query(t, 0, 0, n - 1, l, r);
                }
            }
            else
            {
                printf("%d\n", get(r + 1) - get(l));
            }
        }
    }
    return 0;
}