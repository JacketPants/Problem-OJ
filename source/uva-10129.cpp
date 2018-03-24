#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int g[30][30], n;
int vis[30][30];
int Euler(int u)
{
    for (int v = 0; v < 26; v++)
        if (vis[u][v] < g[u][v] && g[u][v])
        {
            vis[u][v]++;
            return Euler(v) + 1;
        }
    return 0;
}

int main()
{
    int t;
    bool isEuler = false;
    string s;
    cin >> t;
    while (t--)
    {
        isEuler = false;
        memset(g, 0, sizeof g);
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            g[*(s.begin()) - 'a'][*(s.end() - 1) - 'a']++;
        }
        for (int i = 0; i < 26 && !isEuler; i++)
        {
            memset(vis, 0, sizeof vis);
            // cout << Euler(i) << endl;
            isEuler = (Euler(i) == n);
        }
        if (isEuler)
            cout << "Ordering is possible.\n";
        else
            cout << "The door cannot be opened.\n";
    }
    return 0;
}