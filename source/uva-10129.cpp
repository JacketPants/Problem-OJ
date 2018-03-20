#include <iostream>
#include <string>
#include <vector>
using namespace std;
int t, n;
vector<string> list;
bool dfs(int cnt,char m)
{
    if(cnt==n)
        return true;
    // for (int i = 0; i < list.size();i++)

}
int main()
{
    cin >> t;
    string tem;
    while (t--)
    {
        list.clear();
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tem;
            list.push_back(tem);
        }
        if (dfs(0,0))
            puts("Ordering is possible.");
        else
            puts("The door cannot be opened.");
    }
    return 0;
}