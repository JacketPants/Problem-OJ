#include<iostream>
#include<vector>
#include<cstdio>
#define INF 0x3f3f3f3f
using namespace std;
int n,m,w,t,a,b,c;
struct edge{
	int u,v,w;
};
vector<edge> e;
vector<int> list;
bool BellmanFord()
{
	list[1]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<e.size();j++)
			list[e[j].v]=min(list[e[j].v],list[e[j].u]+e[j].w);
	for(int i=0;i<e.size();i++)
		if(list[e[i].v]>list[e[i].u]+e[i].w)
			return false;
	return true;
}
int main()
{
	edge tem;
	cin>>t;
	while(t--)
	{
		e.clear();
		list.clear();
		scanf("%d%d%d",&n,&m,&w);
		for(int i=0;i<n;i++)
			list.push_back(INF);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			tem.u=a;
			tem.v=b;
			tem.w=c;
			e.push_back(tem);
			tem.u=b;
			tem.v=a;
			tem.w=c;
			e.push_back(tem);
		}
		for(int i=0;i<w;i++)
		{
			scanf("%d%d%d",&tem.u,&tem.v,&tem.w);
			tem.w=-tem.w;
			e.push_back(tem);
		}
		if(BellmanFord())
			puts("NO");
		else
			puts("YES");
	}
	return 0;
} 