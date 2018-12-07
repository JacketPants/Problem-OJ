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
        if(a>0&&a%x)
            l++;
        if(b<0&&b%x)
            r--;
        printf("%lld\n",r-l+1); 
    }
    return 0;
}