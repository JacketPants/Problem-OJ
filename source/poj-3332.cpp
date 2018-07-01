#include <iostream>

using namespace std;

int main()
{
    int t,tem;
    cin >> t;
    while(t--)
    {
        cin >> tem;
        if(cin.fail())
            cout << "ILLEGAL\n";
        else
            cout << "LEGAL\n";
    }
    return 0;
}