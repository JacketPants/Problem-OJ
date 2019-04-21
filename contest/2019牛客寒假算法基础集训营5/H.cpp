#include<iostream>
#include<queue>
using namespace std;
long long list[5005];
long long dp[5005][5005];
priority_queue<long long> q;

int main()
{
	int n;
	long long k,sum=0,mi=0,cnt=0;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",list+i);
		q.push(list[i]);
		sum+=list[i];
	}
	while(!q.empty() && sum-mi>k)
	{
		cnt++;
		mi+=q.top();
		q.pop();
	}
	if(sum-mi>k)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n",n-cnt);
	for(int i=1;i<=n;i++)
		for(int j=n-i+1;j;j--)
		{
			if(j==n-i+1)
				dp[j][i]=dp[j+1][i-1]+list[j];
			else
				dp[j][i]=max(dp[j+1][i],dp[j+1][i-1]+list[j]);
		}
	for(int i=1;i<=n;i++)
	{
		if(sum-dp[i+1][cnt]<=k)
			putchar('0');
		else
		{
			putchar('1');
			sum-=list[i];
			cnt--;
		}
	}
	return 0;
} 
