#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long n,m,sum,ans;
	while(~scanf("%lld%lld",&n,&m))
	{
		sum=m*6;
		if(sum>n || n>m*9)
			puts("jgzjgzjgz");
		else
		{
			ans=max(m-n+sum,0LL);
			printf("%lld\n",ans);
		}
	}
	return 0;
 } 
