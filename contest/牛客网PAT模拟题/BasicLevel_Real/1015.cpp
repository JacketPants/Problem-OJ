#include <iostream>
using namespace std;
struct
{
    int add, data, next;
} list[100010];
void Print(int add, int data, int next)
{
    printf("%05d %d %d", add, data, next);
}
int main()
{
    int n, k, m, s;
    cin >> m >> n >> k;
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &list[i].add, & list[i].data, &list[i].next);
    for (int i = 0; i < n; i++)
        if (list[i].add == m)
            s = i;
    for (int i = 0; i < k; i++)
        Print(list[i].add, list[i].data, list[i].next);
    for (int i = k - 1; i >= 0; i--)
        Print(list[s + i].add, list[s + i].data, list[s + i].next);
    for (int i = s + k; i < n; i++)
        Print(list[i].add, list[i].data, list[i].next);
    return 0;
}