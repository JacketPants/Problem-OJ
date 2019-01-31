#include<iostream>
#define MOD 998244353
using namespace std;

int Slove(int n)
{
	int cnt=0;
	for(int i=0;i<n;i++)
		if(i+i==i|i)
			cnt++;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j)
				continue;
			if(i+j==i|j)
				cnt++;
		}
	}
	return cnt;
}

int main()
{
	int n,ans;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		ans=Slove(1<<i);
		cout<<ans<<',';	
	}
	return 0;
} 
