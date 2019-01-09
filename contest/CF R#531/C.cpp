#include<iostream>
#include<algorithm>
using namespace std;
int l[1000];
int main()
{
	int n,x,y,ans=0;
	cin>>n>>x>>y;
	for(int i=0;i<n;i++)
		cin>>l[i];
	if(x<=y)
	{
		for(int i=0;i<n;i++)
			if(l[i]<=x)
				ans++;
		ans=int(ans/2.0+0.5);
	}
	else if(x>y)
	{
		ans=n;
	}
	cout<<ans<<endl;
	return 0;
} 

