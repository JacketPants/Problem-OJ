#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
struct Node
{
    int maxn, minn, sum;
    Node(int maxn = 0, int minn = 0, int sum = 0)
    {
        this->maxn = maxn;
        this->minn = minn;
        this->sum = sum;
    }
} t[1000000];
void Bulid(Node *tree, int *arr, int root, int start, int end)
{
    if (start == end)
    {
        tree[root] = Node(arr[start], arr[start], arr[start]);
    }
    else
    {
        int m = (start + end) / 2;
        Bulid(tree, arr, root * 2 + 1, start, m);
        Bulid(tree, arr, root * 2 + 2, m + 1, end);
        tree[root] = Node(
            max(tree[root * 2 + 1].maxn, tree[root * 2 + 2].maxn),
            min(tree[root * 2 + 1].minn, tree[root * 2 + 2].minn),
            tree[root * 2 + 1].sum + tree[root * 2 + 2].sum);
    }
}

int QueryMax(Node *tree, int root, int start, int end, int qStart, int qEnd)
{
    if (start >= qStart && end <= qEnd)
        return tree[root].maxn;
    else if (qStart > end || qEnd < start)
        return -INF;
    int m = (start + end) / 2;
    return max(QueryMax(tree, root * 2 + 1, start, m, qStart, qEnd),
               QueryMax(tree, root * 2 + 2, m + 1, end, qStart, qEnd));
}
int QueryMin(Node *tree, int root, int start, int end, int qStart, int qEnd)
{
    if (start >= qStart && end <= qEnd)
        return tree[root].minn;
    else if (qStart > end || qEnd < start)
        return INF;
    int m = (start + end) / 2;
    return min(QueryMin(tree, root * 2 + 1, start, m, qStart, qEnd),
               QueryMin(tree, root * 2 + 2, m + 1, end, qStart, qEnd));
}
int QuerySum(Node *tree, int root, int start, int end, int qStart, int qEnd)
{
    if (start >= qStart && end <= qEnd)
        return tree[root].sum;
    else if (qStart > end || qEnd < start)
        return 0;
    int m = (start + end) / 2;
    return QuerySum(tree, root * 2 + 1, start, m, qStart, qEnd) +
           QuerySum(tree, root * 2 + 2, m + 1, end, qStart, qEnd);
}
void Updata(Node *tree, int root, int start, int end, int x, int n)
{
    if (start == end)
    {
        tree[root] = Node(n, n, n);
    }
    else
    {
        int m = (start + end) / 2;
        if (x <= m)
        {
            Updata(tree, root * 2 + 1, start, m, x, n);
        }
        else
        {
            Updata(tree, root * 2 + 2, m + 1, end, x, n);
        }
        tree[root] = Node(
            max(tree[root * 2 + 1].maxn, tree[root * 2 + 2].maxn),
            min(tree[root * 2 + 1].minn, tree[root * 2 + 2].minn),
            tree[root * 2 + 1].sum + tree[root * 2 + 2].sum);
    }
}
int mylist[200001];
int main()
{
    int n, q, l, r, T, op;
    cin >> T;
    while (T--)
    {
        scanf("%d%d", &n, &q);
        for (int i = 0; i < n; i++)
            scanf("%d", mylist + i);
        Bulid(t, mylist, 0, 0, n - 1);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d%d", &op, &l, &r);
            if (op == 2)
            {
                printf("%d\n", QueryMax(t, 0, 0, n - 1, l - 1, r - 1) - QueryMin(t, 0, 0, n - 1, l - 1, r - 1));
            }
            else if (op == 3)
            {
                printf("%d\n", QuerySum(t, 0, 0, n - 1, l - 1, r - 1));
            }
            else
            {
                Updata(t, 0, 0, n - 1, l - 1, r);
            }
        }
    }
    return 0;
}
