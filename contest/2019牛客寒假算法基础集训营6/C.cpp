#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector <pair<int,int>> list(100005);
int main()
{
	int n,m;
	long long ans=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",&list[i].second);
	for(int i=0;i<m;i++)
		scanf("%d",&list[i].first);
	sort(list.rbegin(),list.rend());
	for(pair<int,int> th:list)
	{
		if(th.second<n)
		{
			ans+=th.second*th.first;
			n-=th.second;
		}
		else
		{
			ans+=n*th.first;
			n-=n;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
