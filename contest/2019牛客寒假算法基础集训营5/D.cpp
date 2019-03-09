#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<algorithm>
#define INF_8 0x3f
#define INF_16 0x3f3f
#define INF_32 0x3f3f3f3f
using namespace std;
set<int> s;
set<pair<int,int>> path;
vector<int> mp;
int p[50];
int main()
{
	memset(p,INF_8,sizeof p);
	int n,k,u,v;
	scanf("%d%d",&n,&k);
	s.emplace(1);
	mp.emplace_back(1);
	s.emplace(n);
	mp.emplace_back(n);
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&u,&v);
		if(u>v)
			swap(u,v);
		path.emplace(pair<int,int>(u,v));
		if(!s.count(u))
		{
			s.emplace(u);
			mp.emplace_back(u); 
		}
		if(!s.count(v))
		{
			s.emplace(v);
			mp.emplace_back(v); 
		}
	}
	sort(mp.begin(),mp.end());
	p[0]=0;
	for(int i=0;i<mp.size();i++)
	{
		for(int j=i+1;j<mp.size();j++)
		{
			if(path.count(pair<int,int>(mp[i],mp[j])))
				p[j]=min(p[i]+1,p[j]);
			p[j]=min(p[i]+__builtin_popcount(mp[j]-mp[i]),p[j]);
		}
	}
	cout<<p[s.size()-1]<<endl;
	return 0;
}
