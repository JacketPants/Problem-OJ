#include<iostream>
#include<algorithm>
using namespace std;
long long a[4005];
long long b[2005];
int main()
{
	long long n,x,ans=0;
	scanf("%lld%lld",&n,&x);
	for(int i=0;i<n;i++)
		scanf("%lld",a+i);
	for(int i=0;i<n;i++)
		ans+=a[n+i]=b[i]=a[i];
	for(int i=0;i<n;i++)
	{
		long long sum=x*i;
		for(int j=0;j<n;j++)
		{
			b[j]=min(b[j],a[j+i]);
			sum+=b[j];
		}
		ans=min(sum,ans);
	}
	printf("%lld\n",ans);
	return 0;
}
