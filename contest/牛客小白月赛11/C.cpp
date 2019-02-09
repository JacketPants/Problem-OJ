#include<iostream>
#include<algorithm>
using namespace std;
int x[100005]={0},y[100005]={0},n,m;
int main()
{
	int T,a,b;
	cin>>n>>m>>T;
	for(int day=1;day<=T;day++)
	{
		scanf("%d%d",&a,&b);
		if(a-1)
			y[b-1]=day;
		else
			x[b-1]=day;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			printf("%d%c",max(x[i],y[j]),(j==m-1)?'\n':' ');
		}
	}
	return 0;
 } 
