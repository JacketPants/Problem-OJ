#include<iostream>
#include<cstring>
using namespace std;
bool d[200005];
int main()
{
    memset(d,-1,sizeof d);
    int n,cnt=0,tmp;
    cin>>n;
    while(~scanf("%d",&tmp))
    {
        d[tmp]=false;
    }
    for(int i=1;i<=n;i++)
        if(d[i])
            cout<<i<<endl;
    return 0;
}