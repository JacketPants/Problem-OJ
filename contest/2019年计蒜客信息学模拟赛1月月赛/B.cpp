#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
vector<int> c;
vector<pair<int, int>> b;
vector<int> lm;
int main()
{
    int n, m, tmpa, tmpb, p, q;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &tmpa);
        c.emplace_back(tmpa);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &tmpa, &tmpb);
        b.emplace_back(pair<int, int>(tmpa, tmpb));
    }
    for (int i = 0; i < n; i++)
    {
        
    }
    return 0;
}