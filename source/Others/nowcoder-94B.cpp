#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
int n, q;
int list[100010];
int deep[100010];
int arr[100010];
int r[100010][2];
int main()
{
    stack<int> us;
    stack<int> vs;
    char c;
    int u, v, temu, temv;
    deep[0] = 0;
    while (~scanf("%d", &n))
    {
        memset(arr, 0, sizeof arr);
        for (int i = 1; i < n; i++)
        {
            scanf("%d", list + i);
            deep[i] = deep[list[i]] + 1;
        }

        scanf("%d", &q);
        for (int i = 0; i < q; i++)
        {
            getchar();
            c = getchar();
            if (c == 'R')
            {
                scanf("%d%d", &u, &v);
                temu = u;
                temv = v;
                while (deep[u] != deep[v])
                {
                    if (deep[u] > deep[v])
                    {
                        arr[u]++;
                        r[u][0] = temu;
                        r[u][1] = temv;
                        u = list[u];
                    }
                    else
                    {
                        arr[v]++;
                        r[v][0] = temu;
                        r[v][1] = temv;
                        v = list[v];
                    }
                }
                while (u != v)
                {
                    arr[u]++;
                    r[u][0] = temu;
                    r[u][1] = temv;
                    u = list[u];
                    arr[v]++;
                    r[v][0] = temu;
                    r[v][1] = temv;
                    v = list[v];
                }

                // while (u)
                // {
                //     us.push(u);
                //     u = list[u];
                // }
                // while (v)
                // {
                //     vs.push(v);
                //     v = list[v];
                // }
                // while (!us.empty() && !vs.empty() && us.top() == vs.top())
                // {
                //     us.pop();
                //     vs.pop();
                // }
                // while (!us.empty())
                // {
                //     tem = us.top();
                //     if (arr[tem] == 0)
                //     {
                //         arr[tem]++;
                //         r[tem][0] = temu;
                //         r[tem][1] = temv;
                //     }
                //     else if (arr[tem] == 1)
                //     {
                //         arr[tem]++;
                //     }
                //     us.pop();
                // }
                // while (!vs.empty())
                // {
                //     tem = vs.top();
                //     if (arr[tem] == 0)
                //     {
                //         arr[tem]++;
                //         r[tem][0] = temu;
                //         r[tem][1] = temv;
                //     }
                //     else if (arr[tem] == 1)
                //     {
                //         arr[tem]++;
                //     }
                //     vs.pop();

                //     // arr[vs.top()]++;
                //     // r[vs.top()][0] = temu;
                //     // r[vs.top()][1] = temv;
                //     // vs.pop();
                // }
            }
            else
            {
                scanf("%d", &v);
                if (arr[v] == 0)
                    puts("Not yet");
                else if (arr[v] == 1)
                {
                    if (r[v][0] < r[v][1])
                    {
                        printf("%d %d\n", r[v][0], r[v][1]);
                    }
                    else
                    {
                        printf("%d %d\n", r[v][1], r[v][0]);
                    }
                }
                else
                    puts("Many times");
            }
        }
    }
    return 0;
}