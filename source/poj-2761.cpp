#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
const int maxNode = 100100;
const int INF = 0x3f3f3f3f;
using namespace std;
struct Treap
{
    int root, treapCnt, key[maxNode], priority[maxNode], childs[maxNode][2], cnt[maxNode], size[maxNode];

    Treap()
    {
        root = 0;
        treapCnt = 1;
        priority[0] = INF;
        size[0] = 0;
    }

    void update(int x)
    {
        size[x] = size[childs[x][0]] + cnt[x] + size[childs[x][1]];
    }

    void rotate(int &x, int t)
    {
        int y = childs[x][t];
        childs[x][t] = childs[y][1 - t];
        childs[y][1 - t] = x;
        update(x);
        update(y);
        x = y;
    }

    void __insert(int &x, int k)
    {
        if (x)
        {
            if (key[x] == k)
            {
                cnt[x]++;
            }
            else
            {
                int t = key[x] < k;
                __insert(childs[x][t], k);
                if (priority[childs[x][t]] < priority[x])
                {
                    rotate(x, t);
                }
            }
        }
        else
        {
            x = treapCnt++;
            key[x] = k;
            cnt[x] = 1;
            priority[x] = rand();
            childs[x][0] = childs[x][1] = 0;
        }
        update(x);
    }

    void __erase(int &x, int k)
    {
        if (key[x] == k)
        {
            if (cnt[x] > 1)
            {
                cnt[x]--;
            }
            else
            {
                if (childs[x][0] == 0 && childs[x][1] == 0)
                {
                    x = 0;
                    return;
                }
                int t = priority[childs[x][0]] > priority[childs[x][1]];
                rotate(x, t);
                __erase(x, k);
            }
        }
        else
        {
            __erase(childs[x][key[x] < k], k);
        }
        update(x);
    }

    int __getKth(int &x, int k)
    {
        if (k <= size[childs[x][0]])
        {
            return __getKth(childs[x][0], k);
        }
        k -= size[childs[x][0]] + cnt[x];
        if (k <= 0)
        {
            return key[x];
        }
        return __getKth(childs[x][1], k);
    }

    void insert(int k)
    {
        __insert(root, k);
    }

    void erase(int k)
    {
        __erase(root, k);
    }

    int getKth(int k)
    {
        return __getKth(root, k);
    }
};
struct Query
{
    int a, b, k, no, ans;
};
bool cmpa(Query a, Query b)
{
    return a.a < b.a;
}
bool cmpb(Query a, Query b)
{
    return a.no < b.no;
}
Treap bst;
int list[maxNode];
Query listQ[maxNode];
int main()
{
    int n, m, a = 1, b = 1;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", list + i);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &listQ[i].a, &listQ[i].b, &listQ[i].k);
        listQ[i].no = i;
    }
    sort(listQ, listQ + m, cmpa);
    for (int i = 0; i < m; i++)
    {
        while (b <= listQ[i].b)
            bst.insert(list[b++]);
        while (a < listQ[i].a)
            bst.erase(list[a++]);
        listQ[i].ans = bst.getKth(listQ[i].k);
    }
    sort(listQ, listQ + m, cmpb);
    for (int i = 0; i < m; i++)
        printf("%d\n", listQ[i].ans);
    return 0;
}
