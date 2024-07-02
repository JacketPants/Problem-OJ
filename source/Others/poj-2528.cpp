#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
#define INF 0x3f3f3f
#define MAXN 100010
using namespace std;
struct Node
{
    int color;
};

set<int> ans;
vector<int> mylist;
vector<pair<int, int> > query;
int mp[10000001];
Node t[MAXN * 4];

void Bulid(Node *tree, int root, int start, int end)
{
    if (start == end)
    {
        tree[root].color = -1;
    }
    else
    {
        int m = (start + end) / 2;
        Bulid(tree, root * 2 + 1, start, m);
        Bulid(tree, root * 2 + 2, m + 1, end);
        tree[root].color = -1;
    }
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

void Query(Node *tree, int root, int start, int end, int qStart, int qEnd)
{
    if (tree[root].color != -1)
    {
        ans.insert(tree[root].color);
        return;
    }
    else if (qStart > end || qEnd < start)
        return;
    int m = (start + end) / 2;
    Query(tree, root * 2 + 1, start, m, qStart, qEnd);
    Query(tree, root * 2 + 2, m + 1, end, qStart, qEnd);
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
}

int main()
{
    int tt, q, a, b, sum;
    cin >> tt;
    while (tt--)
    {
        sum = 0;
        ans.clear();
        mylist.clear();
        query.clear();
        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d", &a, &b);
            query.push_back(pair<int, int>(a, b));
            mylist.push_back(a);
            mylist.push_back(b);
        }
        sort(mylist.begin(), mylist.end());
        mp[mylist[0]] = sum++;
        for (int i = 1; i < mylist.size(); i++)
        {
            if (mylist[i] == mylist[i - 1])
                continue;
            if (mylist[i] - mylist[i - 1] > 1)
                sum++;
            mp[mylist[i]] = sum++;
        }
        sum--;
        Bulid(t, 0, 0, sum);
        for (int i = 0; i < query.size(); i++)
        {
            Updata(t, 0, 0, sum, mp[query[i].first], mp[query[i].second], i);
        }
        Query(t, 0, 0, sum, 0, sum);
        printf("%d\n", ans.size());
    }
    return 0;
}

/*
100
5
1 4
2 6
8 10
3 4
7 10
5
1 10000000
100 10000000
2 1234
34 9999999
1 99
*/
