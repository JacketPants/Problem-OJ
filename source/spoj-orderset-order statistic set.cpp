#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> bst;
//用splay和ov_tree会TLE
//tree<int, null_type, less<int>, splay_tree_tag, tree_order_statistics_node_update> bst;
//tree<int, null_type, less<int>, ov_tree_tag, tree_order_statistics_node_update> bst;

int main()
{
    int t, val;
    char ch;
    scanf("%d", &t);
    while (t--)
    {
        getchar();
        ch = getchar();
        scanf("%d", &val);
        if (ch == 'I')
            bst.insert(val);
        else if (ch == 'D')
            bst.erase(val);
        else if (ch == 'K')
        {
            if (bst.size() >= val)
                printf("%d\n", *bst.find_by_order(val - 1));
            else
                puts("invalid");
        }
        else
            printf("%d\n", bst.order_of_key(val));
    }
    return 0;
}