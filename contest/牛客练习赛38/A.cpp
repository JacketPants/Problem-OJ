#include<iostream>
#include<algorithm>
using namespace std;
int list[100005];
int main()
{
    int n,x;
    cin>>n>>x;
    double ans=x;
    for(int i=0;i<n;i++)
    {
        scanf("%d",list+i);
    }
    sort(list,list+n);
    for(int i=0;i<n;i++)
    {
    	if(list[i]>ans)
    		ans=(ans+list[i])/2.0;
	}
    printf("%0.3lf\n",ans);
    return 0;
}
