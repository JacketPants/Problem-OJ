// #include <algorithm>
// #include <cstring>
// #include <iostream>
// #include <map>
// #include <set>
// #include <vector>
// using namespace std;
// set<int> s;
// map<int, int> l;
// template <class T>
// inline bool scan_d(T &ret)
// {
//     char c;
//     int sgn;
//     if (c = getchar(), c == EOF)
//         return 0;
//     while (c != '-' && (c < '0' || c > '9'))
//         c = getchar();
//     sgn = (c == '-') ? -1 : 1;
//     ret = (c == '-') ? 0 : (c - '0');
//     while (c = getchar(), c >= '0' && c <= '9')
//         ret = ret * 10 + (c - '0');
//     ret *= sgn;
//     return 1;
// }

// struct Node
// {
//     int n, cnt;
//     Node()
//     {
//         this->n = 0;
//         this->cnt = 0;
//     }
//     Node(int n, int cnt)
//     {
//         this->n = n;
//         this->cnt = cnt;
//     }
// };

// bool cmp(Node &a, Node &b)
// {
//     if (a.cnt == b.cnt)
//         return a.n < b.n;
//     return a.cnt > b.cnt;
// }
// vector<Node> list;
// int ans[100001];
// int main()
// {
//     int t, n, m, tem, len;
//     bool flag = false;
//     cin >> t;
//     while (t--)
//     {
//         memset(ans, 0, sizeof ans);
//         flag = false;
//         s.clear();
//         l.clear();
//         list.clear();
//         scanf("%d%d", &n, &m);
//         for (int i = 0; i < n; i++)
//         {
//             scan_d(tem);
//             s.insert(tem);
//             l[tem]++;
//         }
//         for (auto i : l)
//             list.push_back(Node(i.first, i.second));
//         sort(list.begin(), list.end(), cmp);
//         len = list.size();
//         // todo: 写需要去几个数才能成为众数
//         for (int i = 1; i < len; i++)
//         {
//             // sum.push_back(list[i - 1] - list[i] + 1);
//             ans[list[i].n] = ans[list[i - 1].n] + 1 + i * (list[i - 1].cnt - list[i].cnt);
//         }
//         for (set<int>::reverse_iterator i = s.rbegin(); i != s.rend(); i++)
//         {
//             if (ans[*i] <= m)
//             {
//                 printf("%d\n", *i);
//                 flag = true;
//                 break;
//             }
//         }
//         if (!flag)
//             puts("-1");
//     }
//     return 0;
// }
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
map<int, int> list, cnt, ans;
int main()
{
    int t, n, m, tem, sum, out, maxn;
    cin >> t;
    while (t--)
    {
        list.clear();
        cnt.clear();
        ans.clear();
        sum = maxn = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tem);
            list[tem]++;
        }
        for (auto i : list)
        {
            maxn = max(maxn, ++cnt[i.second]);
        }
        for (int i = maxn + 1; i >= 0; i--)
        {
            ans[i] = ans[i + 1] + (bool)ans[i + 1] + sum + cnt[i] - 1;
            sum += cnt[i];
        }
        out = -1;
        for (int i = n; i; i--)
        {
            if (ans[list[i]] <= m)
            {
                out = i;
                break;
            }
        }
        printf("%d\n", out);
    }
    return 0;
}

/*
2 2 
1 1


29 8
9 9 9 9 9
8 8 8 8 8
7 7 7 7 7
6 6 6 6 6
10 10 10 10
3 3 3 3
4
*/
