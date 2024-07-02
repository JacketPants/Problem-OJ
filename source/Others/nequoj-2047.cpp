#include <iostream>
#include <map>
#include <stack>
using namespace std;
map<int, bool> vis;
stack<int> s;
int list[10000000];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    for (int i = n - 1; i >= 0; i--)
    {
        if (!vis[list[i]])
        {
            vis[list[i]] = true;
            s.push(list[i]);
        }
    }
    printf("%d\n", s.size());
    while (!s.empty())
    {
        printf("%d", s.top());
        s.pop();
        if (s.empty())
            putchar('\n');
        else
            putchar(' ');
    }
    return 0;
}