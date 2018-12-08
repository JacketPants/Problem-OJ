#include<iostream>
#include<algorithm>
using namespace std;
int list[1000005],ans[1000006]={0};
int main()
{
    int x,n,k,a=0,b=0;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&x);
        list[x]++;
    }
    for(int i=1;i<=k;i++)
    {
        if(list[i])
            for(int j=i;j<=k;j+=i)
            {
                ans[j]+=list[i];
            }
    }
    for(int i=1;i<=k;i++)
		a=max(a,ans[i]); 
    for(int i=1;i<=k;i++)
        if(ans[i]==a)
            b++;
    printf("%d %d\n",a,b);
    return 0;
}
