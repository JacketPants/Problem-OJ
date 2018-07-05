#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char mymap[1002][1002];
int dfs(int x,int y)
{
	if(mymap[x][y]=='@')
	{
		int ans=1;
		mymap[x][y]='#';
		ans+=dfs(x+1,y);
		ans+=dfs(x,y+1);
		ans+=dfs(x,y-1);
		ans+=dfs(x-1,y);
		ans+=dfs(x+1,y+1);
		ans+=dfs(x-1,y+1);
		ans+=dfs(x+1,y-1);
		ans+=dfs(x-1,y-1);
		return ans;
	}
	return 0;
}
int main()
{
	int m,n,ans;
	while(~scanf("%d%d",&m,&n),m||n)
	{
		ans=0;
		memset(mymap,'#',sizeof(mymap));
		for(int i=1;i<=m;i++)
		{
			scanf("%s",&mymap[i][1]);
			mymap[i][n+1]='#';
		}
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(mymap[i][j]=='@')
					ans=max(ans,dfs(i,j));
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}