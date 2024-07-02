// #include <cstring>
// #include <iostream>
// using namespace std;

// int main()
// {
//     int t, n, k, p;
//     bool vis[20] = {true};
//     cin >> t;
//     while (t--)
//     {
//         memset(vis, -1, sizeof vis);
//         cin >> n >> k;
//         p = 1;
//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < k; p %= n)
//             {
//                 if (vis[p])
//                     j++;
//                 if (j < k)
//                     p++;
//             }
//             vis[p] = false;
//             if (i)
//                 putchar(' ');
//             if (!p)
//                 printf("%d", n);
//             else
//                 printf("%d", p);
//         }
//         putchar('\n');
//     }
//     return 0;
// }
/*
3
10 3
5 2
11 4
*/
#include <cstdio>
#include <cstdlib>
#include<iostream>
using namespace std;


typedef struct __Node
{
    int id;
    struct __Node* next;
}Node;

void Play(int n, int m)
{
    Node* lst = (Node*)malloc(sizeof(Node)*n);
    int i;
    for(i=0; i<n; i++)
    {
        lst[i].id = i+1;
        if(i+1 == n)
            lst[i].next = &lst[0];
        else
            lst[i].next = &lst[i+1];
    }

    Node* cur = &lst[0];
    Node* prev = &lst[n-1];

    int count = 0;
    while(prev != cur)
    {
        count ++;
        if(count == m)
        {
            count = 0;
            cout << cur->id << ' ';
            prev->next = cur->next;
            cur = cur->next;

        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    cout << cur->id <<endl;
    free(lst);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        Play(n, k);
    }
}