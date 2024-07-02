#include <iostream>

using namespace std;

int main()
{
    int n,x,y;
    cin >> n;
    for (int _ = 0; _ < n; _++)
    {
        cin>>x>>y;
        if (y>=-1)
            cout<<"YES\n";
        else
            cout<<"NO\n";        
    }
    return 0;
}