#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, tmp;
    while (~scanf("%d", &n))
    {
        vector<int> list;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            list.emplace_back(tmp);
        }
        sort(list.rbegin(), list.rend());
        int p = 0, q = n - 1;
        printf("%d", list[p++]);
        for (int i = 1; i < n; i++)
        {
            if (i & 1)
                printf(" %d", list[q--]);
            else
                printf(" %d", list[p++]);
        }
        puts("");
    }
    return 0;
}