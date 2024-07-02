#include <iostream>
#include <map>
#include <stack>
using namespace std;
int list[100];
map<int, bool> vis;
int main()
{
    int n, m = 0;
    stack<int> s;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    for (int i = n - 1; i >= 0; i--)
    {
        if (!vis[list[i]])
        {
            s.push(list[i]);
            vis[list[i]] = true;
            m++;
        }
    }
    printf("%d\n", m);
    bool flag = false;
    while(!s.empty())
    {
        if(flag)
            putchar(' ');
        else
            flag = !flag;
        printf("%d", s.top());
        s.pop();
    }
    return 0;
}