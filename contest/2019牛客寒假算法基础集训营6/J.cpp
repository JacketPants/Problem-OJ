#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
char p[1005][1005];
bool vis[1005][1005];
struct S
{
	int x,y,cx,cy;
	S(int x=0,int y=0,int cx=0,int cy=0)
	{
		this->x=x;
		this->y=y;
		this->cx=cx;
		this->cy=cy;
	}
};
queue<S> q;
int main()
{
	int n,m,r,c,x,y,ans=0;
	scanf("%d%d%d%d%d%d",&n,&m,&r,&c,&x,&y);
	memset(p,'*',sizeof p);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
			p[i][j]=getchar();
	}
	S now;
	vis[r][c]=true;
	q.push(S(r,c,x,y));
	while(!q.empty())
	{
		now=q.front();q.pop();
		cout<<now.x<<' '<<now.y<<endl;
		ans++;
		if(now.cx && p[now.x][now.y-1]!='*' && !vis[now.x][now.y-1])
		{
			q.push(S(now.x,now.y-1,now.cx-1,now.cy));
			vis[now.x][now.y-1]=true;
		}
		if(now.cy && p[now.x][now.y+1]!='*' && !vis[now.x][now.y+1])
		{
			q.push(S(now.x,now.y+1,now.cx,now.cy-1));
			vis[now.x][now.y+1]=true;
		}
		if(p[now.x-1][now.y]!='*' && !vis[now.x-1][now.y])
		{
			q.push(S(now.x-1,now.y,now.cx,now.cy));
			vis[now.x-1][now.y]=true;
		}
		if(p[now.x+1][now.y]!='*' && !vis[now.x+1][now.y])
		{
			q.push(S(now.x+1,now.y,now.cx,now.cy));
			vis[now.x+1][now.y]=true;
		}
	}
	printf("%d\n",ans);
	return 0;
}
