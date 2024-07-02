#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int n,a,b,v[100],ans;
	while(~scanf("%d",&n)&&n)
	{
		ans=0;
		memset(v,0,sizeof v);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			for(int j=b+1;j<100;j++)
				ans+=v[j];
			ans%=1000000;
			v[b]++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
