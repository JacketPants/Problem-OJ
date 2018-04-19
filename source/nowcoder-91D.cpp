#include<iostream>
using namespace std;
bool isMod(int a,int b,int m)
{
    if(b-a>=m)
        return true;
    int c=a%m;
    c=a-c;
    if((c>=a&&c<=b) || (c+m>=a&&c+m<=b))
        return true;
    return false;
}
bool isCanntMod(int a,int b,int m)
{
    if(b-a>=m)
        return false;
    int c=a%m;
    c=a-c;
    if((c>=a&&c<=b) || (c+m>=a&&c+m<=b))
        return false;
    return true;
}
int main()
{
    int t,a,b,c,d,m;
    cin>>t;
    while(t--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&m);
        if(isMod(a,b,m)&&isMod(c,d,m))
            puts("LOSE");
        else
        {
            puts("WIN");
        }
    }
    return 0;
}