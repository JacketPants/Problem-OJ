#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[2][1<<5];
int m,n,s;
void dfs(int j, int now, int next)
{
	if(j==n)
	{
//		cout<<next<<endl;
		dp[1][next]+=max(dp[0][now],1);
		dp[1][next]%=1000000007;
		return;
	}
	if(!((1<<j)&now))
	{
		dfs(j+1,now,next|(1<<j));
	}
	else
	{
		dfs(j+1,now,next);
		if(j+2<=n && ((1<<(j+1))&now))
		{
//			cout<<j<<"!\n";
			dfs(j+2,now,(next|(1<<j))|(1<<(j+1)));
		}
	}
} 
int main()
{
	while(~scanf("%d%d",&m,&n))
	{
		s=1<<n;
		memset(dp,0,sizeof(dp));
		dfs(0,s-1,0);
		
		for(int i=0;i<s;i++)
			cout<<dp[1][i]<<' ';
		putchar('\n');
		
		for(int i=1;i<m;i++)
		{
			for(int j=0;j<s;j++)
				if(dp[i][j])
					dfs(0,j,0);
					
			for(int i=0;i<s;i++)
			cout<<dp[1][i]<<' ';
			putchar('\n');
		
			for(int j=0;j<s;j++)
			{
				dp[0][j]=dp[1][j];
				dp[1][j]=0;
			}
		}
		cout<<dp[0][s-1]<<endl;
	}
	return 0;
}
