#include<iostream>

using namespace std;

int main()
{
	long long n,m,d,x,ans;
	while(~scanf("%lld%lld%lld%lld",&n,&m,&d,&x))
	{
		long long sum=0;
		for(int i=1;i<=x;i++)
		{
			sum+=n;
			n+=d;
			if(m<=sum)
			{
				printf("%lld\n",i);
				break;
			}
		}
	}
	return 0;
}
