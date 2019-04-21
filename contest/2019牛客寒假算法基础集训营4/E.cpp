#include<iostream>
#include<cmath>
#define MOD 1000000007
using namespace std;

int main()
{
	const int x=7;
	cout<<int(pow(2,12))%x<<endl;
	cout<<int(pow(2,12%x))%x<<endl;
	int n,m,ans=1;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		ans<<1;
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}
