// #include <cstring>
// #include <iostream>
// #include <queue>
// using namespace std;
// struct Step
// {
//     int x, y, t, l;
//     Step(int x = 0, int y = 0, int t = 0, int l = 0)
//     {
//         this->x = x;
//         this->y = y;
//         this->t = t;
//         this->l = l;
//     }
//     bool operator<(const Step &x) const
//     {
//         return this->l < x.l;
//     }
// };
// int g[10][10];
// bool vis[10][10];
// int pos[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
// int main()
// {
//     int t, n, m;
//     Step tem;
//     scanf("%d", &t);
//     while (t--)
//     {
//         bool isOut = false;
//         priority_queue<Step> q;
//         memset(g, 0, sizeof g);
//         memset(vis, 0, sizeof vis);
//         scanf("%d%d", &n, &m);
//         for (int i = 1; i <= n; i++)
//             for (int j = 1; j <= m; j++)
//             {
//                 scanf("%d", &g[i][j]);
//                 if (q.empty() && g[i][j] == 2)
//                     q.push(Step(i, j, 0, 6));
//             }
//         while (!q.empty())
//         {
//             tem = q.top();
//             q.pop();
//             // vis[tem.x][tem.y] = true;
//             // printf("%d\n", g[tem.x][tem.y]);
//             if (g[tem.x][tem.y] == 3)
//             {
//                 isOut = true;
//                 break;
//             }
//             if (tem.l > 1)
//                 for (int i = 0; i < 4; i++)
//                 {
//                     if (!vis[tem.x + pos[i][0]][tem.y + pos[i][1]] && g[tem.x + pos[i][0]][tem.y + pos[i][1]])
//                     {
//                         // vis[tem.x + pos[i][0]][tem.y + pos[i][1]] = true;
//                         if (g[tem.x + pos[i][0]][tem.y + pos[i][1]] == 4)
//                             q.push(Step(tem.x + pos[i][0], tem.y + pos[i][1], tem.t + 1, 6));
//                         else
//                             q.push(Step(tem.x + pos[i][0], tem.y + pos[i][1], tem.t + 1, tem.l - 1));
//                     }
//                 }
//         }
//         if (isOut)
//             printf("%d\n", tem.t);
//         else
//             printf("-1\n");
//     }
//     return 0;
// }

// #include <cstring>
// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;
// struct P
// {
//     int x, y;
// };

// int main()
// {
//     int t;
//     scanf("%d", &t);
//     while(t--)
//     {
//         queue
//     }
//     return 0;
// }