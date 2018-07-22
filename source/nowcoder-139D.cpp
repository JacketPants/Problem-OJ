#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

#define G vector<Edge>

using namespace std;

struct Edge
{
    int a, b;
};
bool tar[8][8];
int phi[8];

unordered_set<G> ans;
int main()
{
    int n, m1, m2;
    bool ok;
    while (~scanf("%d%d%d", &n, &m1, &m2))
    {
        G g1(m1), g2(m2), tem(m1);
        memset(tar, 0, sizeof tar);
        for (int i = 0; i < m1; i++)
        {
            scanf("%d%d", &g1[i].a, &g1[i].b);
            g1[i].a--;
            g1[i].b--;
        }
        for (int i = 0; i < m2; i++)
        {
            scanf("%d%d", &g2[i].a, &g2[i].b);
            g2[i].a--;
            g2[i].b--;
        }
        for (int i = 0; i < g2.size(); i++)
        {
            tar[g2[i].a][g2[i].b] = tar[g2[i].b][g2[i].a] = true;
        }
        itoa(phi, phi + n, 0);
        do
        {
            ok = true;
            for (int i = 0; i < m1; i++)
            {
                tem[i].a = phi[g1[i].a];
                tem[i].b = phi[g1[i].b];
                ok &= tar[tem[i].a][tem[i].b];
            }
            ansa += ok;
        } while (next_permutation(phi, phi + n));
        printf("%d\n", ans.size());
    }
    return 0;
}