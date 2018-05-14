#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
int list[1000];
int maxn = 0, n;
map<int, int> cnt;
int FindLast(int n)
{
    for (int i = 0; i < n; i++)
        if (list[i] == n)
            return i;
    return -1;
}
int main()
{
    bool flag = false;
    priority_queue<int> q;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", list + i);
        if (!cnt[list[i]])
            q.push(list[i]);
        cnt[list[i]]++;
    }
    int len = q.size();
    int a, b, c, d, ans = 0;
    for (int i = 1; i < len; i++)
    {
        d = 0;
        a = q.top();
        q.pop();
        b = q.top();
        c = FindLast(a);
        for (int j = c + 1; j < n; j++)
            if (list[j] == b)
                d++;
        if (d)
        {
            flag = true;
            ans += d;
            q.pop();
            break;
        }
    }
    if (flag)
        while (!q.empty())
        {
            ans += cnt[q.top()];
            q.pop();
        }
    cout << ans << endl;
    return 0;
}
/*
11
4 3 4 5 1 3 2 3 4 5 4
7

10
4 3 4 5 5 1 2 3 3 4 
6

10
6 4 3 4 5 1 2 3 3 4 
9

10
4 3 4 5 1 3 4 5 3 2
6

5
4 5 1 3 2
3

4
2 1 4 3
3
*/