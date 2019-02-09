#include<iostream>
#include<cmath>
#include<set>
using namespace std;
pair<int,int> base[100050];
set<int> f;
pair<int,int> slove(int n)
{
	pair<int,int> ans(1,n);
	bool flag=true;
	while(flag)
	{
		flag=false;
		for(int i=1;base[i].second<=ans.second;i++)
		{
			if(ans.second%base[i].second==0)
			{
				ans.first*=base[i].first;
				ans.second/=base[i].second;
				flag=true;
				break;
			}
		}
	}
	return ans;
}
void Init()
{
	int maxn=5000;
	for(int i=2;i<=maxn;i++)
	{
		if(!base[i].first)
			base[++base[0].first].first=i;
		for(int j=1;j<=base[0].first&&base[j].first<=maxn/i;j++)
		{
			base[base[j].first*i].first=1;
			if(i%base[j].first==0)
				break;
		}
	}
	for(int i=1;i<=450;i++)
	{
		base[i].second=base[i].first*base[i].first;
		f.insert(base[i].second);
	}
}
int main()
{
	Init();
	int t,n;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		if(n>10000000)
			puts("!");
		else if(n<0)
			puts("-1");
		else
		{
			pair<int,int> ans=slove(n);
			printf("%d %d\n",ans.first,ans.second);			
		}
	}
	return 0;
}
