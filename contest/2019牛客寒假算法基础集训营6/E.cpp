#include<iostream>
#include<cstring>
using namespace std;
int p[2000005];
int n,m;
int GetPos(int x,int y)
{
	return x*m+y;	
}
int Cnt(int a,int b,int x,int y)
{
	return p[GetPos(x,y)]-p[GetPos(a-1,y)]-p[GetPos(x,b-1)]+p[GetPos(a-1,b-1)]; 
}
int main()
{
	int a,b,x,y,d,q,tmp;
	memset(p,0,sizeof p);
    scanf("%d%d%d",&n,&m,&d);
    for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=m;j++)
    	{
    		scanf("%d",&tmp);
    		p[GetPos(i,j)]=p[GetPos(i-1,j)]+p[GetPos(i,j-1)]-p[GetPos(i-1,j-1)]+(tmp>=d);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&a,&b,&x,&y);
		printf("%d\n",Cnt(a,b,x,y));
	}
    return 0;
}
