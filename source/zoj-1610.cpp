#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#define INF 0x3f3f3f
#define MAXN 10010
using namespace std;
struct Node
{
    int color;
};

map<int, int> ans;
int pre[10000];
Node t[MAXN * 4];

void Bulid(Node *tree, int root, int start, int end)
{
    tree[root].color = -1;
    if (start == end)
    {
        return;
    }
    int m = (start + end) / 2;
    Bulid(tree, root * 2 + 1, start, m);
    Bulid(tree, root * 2 + 2, m + 1, end);
    // cout << tree[root].color << endl;
}

void PushDown(Node *tree, int root)
{
    if (tree[root].color >= 0)
    {
        tree[root * 2 + 1].color = tree[root].color;
        tree[root * 2 + 2].color = tree[root].color;
        tree[root].color = -1;
    }
}

void Query(Node *tree, int root, int start, int end)
{
    if (tree[root].color != -1)
    {
        if (pre[tree[root].color] == -1 || pre[tree[root].color] + 1 < start)
            ans[tree[root].color]++;
        pre[tree[root].color] = end;
        return;
    }
    else if (end == start)
        return;
    int m = (start + end) / 2;
    Query(tree, root * 2 + 1, start, m);
    Query(tree, root * 2 + 2, m + 1, end);
}

void Updata(Node *tree, int root, int start, int end, int uStart, int uEnd, int n)
{
    if (start > uEnd || end < uStart)
        return;
    if (uStart <= start && end <= uEnd)
    {
        tree[root].color = n;
        return;
    }
    PushDown(tree, root);
    int m = (start + end) / 2;
    Updata(tree, root * 2 + 1, start, m, uStart, uEnd, n);
    Updata(tree, root * 2 + 2, m + 1, end, uStart, uEnd, n);
    if (tree[root * 2 + 1].color == tree[root * 2 + 2].color)
        tree[root].color = tree[root * 2 + 1].color;
}

int main()
{
    int n, a, b, c;
    while (~scanf("%d", &n))
    {
        memset(pre, -1, sizeof pre);
        ans.clear();
        Bulid(t, 0, 0, 10000);
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            Updata(t, 0, 0, 10000, a, b - 1, c);
        }
        Query(t, 0, 0, 10000);
        for (auto th : ans)
        {
            printf("%d %d\n", th.first, th.second);
        }
        puts("");
    }
    return 0;
}
