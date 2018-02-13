#include<iostream>
#include<cstdio>
using namespace std;
char mymap[4][4];
bool isArr[4][4];
bool Check()
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(mymap[i][j]!=mymap[0][0])
				return false;
	return true;
}
bool isIn(int i, int j)
{
	if(i<4&&i>=0&&j<4&&j>=0)
		return true;
	return false;
}
void filp(int i, int j)
{
	if(isIn(i,j))
		mymap[i][j]=!mymap[i][j];
	if(isIn(i+1,j))
		mymap[i+1][j]=!mymap[i+1][j];
	if(isIn(i,j+1))
		mymap[i][j+1]=!mymap[i][j+1];
	if(isIn(i-1,j))
		mymap[i-1][j]=!mymap[i-1][j];
	if(isIn(i,j-1))
		mymap[i][j-1]=!mymap[i][j-1];
}
bool dfs(int i, int j, int n)
{
	if(!n)
		return Check();
	//枚举，组合数 
	for(i+=j/4;i<4;i++,j=0)
		for(j%=4;j<4;j++)
		{
			filp(i,j);
			if(dfs(i,j+1,n-1))
				return true;
			filp(i,j);
		}
	return false;
}
int main()
{
	int ans;
	for(int i=0;i<4;i++)
		scanf("%s",mymap[i]);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			mymap[i][j]=mymap[i][j]=='b'?1:0;
	for(ans=0;ans<=16;ans++)
		if(dfs(0,0,ans))
			break;
	if(ans<=16)
		cout<<ans<<endl;
	else
		puts("Impossible");
	return 0;
}
