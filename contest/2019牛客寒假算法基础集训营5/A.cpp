#include<iostream>
#include<cmath>
using namespace std;
bool cmp(double a,double b,bool equal=false)
{
    double dis=abs(a-b);
    if(dis<=1e-6)
        return equal;
    return a<b;
}
int main()
{
    double l1,l2,x,y,len,ans;
    int T;
    cin>>l1>>l2>>T;
    while(T--)
    {
        cin>>x>>y;
        len=sqrt(x*x+y*y);
        if(l1>l2)
        {
            if(len<l1-l2)
                ans=l1-l2-len;
            else if(l1+l2<len)
                ans=len-l1-l2;
            else
                ans=0;
            // if(l1-l2<=len && len<=l1+l2)
            // // if(cmp(l1-l2,len,true) && cmp(len,l1+l2,true))
            // {
            //     ans=0;
            // }
            // else
            // {
            //     if(len<l1-l2)
            //     // if(cmp(len,l1-l2))
            //     {
            //         ans=l1-l2-len;
            //     }
            //     else
            //     {
            //         ans=len-l1-l2;
            //     }
            // }
        }
        else
        {
            if(len<(l2-l1)/2.0)
                ans=(l2-l1)/2.0-len;
            else if(len>l1+l2)
                ans=len-l1-l2;
            else
                ans=0;
            // if(len<=l1+l2)
            // // if(cmp(len,l1+l2,true))
            // {
            //     ans=0;
            // }
            // else
            // {
            //     ans=len-l1-l2;
            // }
        }
        printf("%.8lf\n",ans);
    }
    return 0;
}