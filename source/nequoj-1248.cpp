#include<iostream>

using namespace std;

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n%2==0)
            cout<<4<<endl;
        else
            cout<<4+(n/2)*2<<endl;
    }
    return 0;
}
