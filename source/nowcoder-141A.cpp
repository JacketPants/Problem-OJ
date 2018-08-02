#include <iostream>

using namespace std;
int dp[37][37][37][37];
bool ch[37][37][37][37][37];
int p[37], a[37], c[37], m[37], g[37];
bool path[37];
int main()
{
    int N, P, A, C, M;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d%d%d%d%d", p + i, a + i, c + i, m + i, g + i);
    scanf("%d%d%d%d", &P, &A, &C, &M);
    for (int i = 0; i < N; i++)
        for (int pi = P; pi >= p[i]; pi--)
            for (int ai = A; ai >= a[i]; ai--)
                for (int ci = C; ci >= c[i]; ci--)
                    for (int mi = M; mi >= m[i]; mi--)
                        if (dp[pi][ai][ci][mi] < dp[pi - p[i]][ai - a[i]][ci - c[i]][mi - m[i]] + g[i])
                        {
                            dp[pi][ai][ci][mi] = dp[pi - p[i]][ai - a[i]][ci - c[i]][mi - m[i]] + g[i];
                            ch[i][pi][ai][ci][mi] = true;
                        }
    int ans = 0;
    for (int i = N - 1; i >= 0; i--)
        if (ch[i][P][A][C][M])
        {
            path[i] = true;
            ans++;
            P -= p[i];
            A -= a[i];
            C -= c[i];
            M -= m[i];
        }
    printf("%d\n", ans);
    for (int i = 0; i < N; i++)
    {
        if (path[i])
            printf("%d\n", i);
    }
    return 0;
}
