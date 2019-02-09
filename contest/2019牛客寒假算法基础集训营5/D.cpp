#include<iostream>
#include<map>
#include<memset>
#define INF_8 0x3f
#define INF_16 0x3f3f
#define INF_32 0x3f3f3f3f
using namespace std;
map<int,int> mp;
int rmp[50];
int p[50][50];
int main()
{
	memset(p,INF_8,sizeof p);
	int n,k,u,v,cnt=0,from=0,to;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i<<1)
	{
		if(cnt)
			p[cnt-1][cnt]=1;
		rmp[cnt]=i;
		mp[i]=cnt++;
	}
	if(!(to=mp[n]))
	{
		rmp[cnt]=n;
		mp[n]=cnt;
		to=cnt++;
		p[cnt-1][cnt]=n-rmp[cnt-1]-1;	
	}
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&u,&v);
		if(!mp[u])
		{
			rmp[cnt]=u;
			mp[u]=cnt++;
		}
		if(!mp[v])
		{
			rmp[cnt]=v;
			mp[v]=cnt++;
		}
	}
	return 0;
}
