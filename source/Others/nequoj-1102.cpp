#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long a,b,c,d,e,ans;
    while(cin>>a>>b>>c)
    {
        ans=a%c;
        for(int i=1;i<b;i++)
        {
            ans*=a;
            ans%=c;
        }
        cout<<ans<<endl;
    }
    return 0;
}
