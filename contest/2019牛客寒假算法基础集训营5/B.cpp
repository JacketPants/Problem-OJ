#include<iostream>
#include<set>
#include<cstring>
using namespace std;
set<pair<int,int>> s[2];
int pos[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{-1,1},{1,-1}};
int Count(int x, int y, int id, int i)
{
	int cnt=1;
	while(cnt<=4)
	{
		if(!s[id].count(pair<int,int>(x+cnt*pos[i][0],y+cnt*pos[i][1])))
			return cnt-1;
		cnt++;
	}
	return cnt-1;
}
bool Check(int x,int y, int id)
{
	for(int i=0;i<8;i+=2)
		if(Count(x,y,id,i)+Count(x,y,id,i+1)>=4)
			return true;
	return false;
}
int main()
{
	int n,m,x,y,id=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&x,&y);
		if(Check(x,y,id))
			puts("Y");
		else
			puts("N");
		s[id].emplace(pair<int,int>(x,y));
		id=!id;
	}
	return 0;
}
