#include<iostream>

using namespace std;
int a[100005];
int main()
{
	int n;
	long long ans=0,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	
	for(int i=0;i<n;i++)
	{
		if(a[i])
		{
			cnt+=a[i];
		}
		else
		{
			ans+=cnt/2;
			cnt=0;
		}
	}
	ans+=cnt/2;
	printf("%lld\n",ans);
	return 0;
}
