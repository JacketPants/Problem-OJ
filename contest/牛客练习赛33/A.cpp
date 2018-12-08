#include<iostream>

using namespace std;

int main()
{
    long long l,a,b,r,x,ans;
    int t;
    cin>>t;
    while(t--)
    {
        scanf("%lld%lld%lld",&a,&b,&x);
        l=a/x;
        r=b/x;
        if(a%x)
            l++;
        printf("%lld\n",r-l+1); 
    }
    return 0;
}