#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t,n,a,b;
    string s;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(!n)
        {
            cin>>a>>b;
            cout<<a+b<<endl;
        }
        else
        {
            cin>>s;
            cout<<s.length()<<endl;
        }
    }
    return 0;
}