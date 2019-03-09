#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool dp[3005][3005];
int p[3005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n,s,t,ps,pt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",p+i);
	memset(dp,0,sizeof dp);
	s=p[1];
	t=p[n];
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(p[i]==s)
			ps=i;
		else if(p[i]==t)
			pt=i;
	}
	dp[ps][s]=true;
	for(int i=3000;i>=0;i--)
	{
		
	}
    return 0;
}
