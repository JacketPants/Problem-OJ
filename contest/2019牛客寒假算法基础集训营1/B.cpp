#include<iostream>

using namespace std;
int cnt[3];
int main()
{
	int n,tmp,last=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		cnt[tmp/2]++;
	}
	for(int i=0;i<n;i++)
	{
		if(last==0)
		{
			if(cnt[2])
			{
				cnt[2]--;
				last=4;
				ans+=16;
			}
			else if(cnt[1])
			{
				cnt[1]--;
				last=2;
				ans+=4;
			}
			else
			{
				cnt[0]--;
				last=0;
			}
		}
		else if(last==2)
		{
			if(cnt[2])
			{
				cnt[2]--;
				last=4;
				ans+=4;
			}
			else if(cnt[0])
			{
				cnt[0]--;
				last=0;
				ans+=4;
			}
			else
			{
				cnt[1]--;
				last=2;
			}
		}
		else
		{
			if(cnt[0])
			{
				cnt[0]--;
				last=0;
				ans+=16;
			}
			else if(cnt[1])
			{
				cnt[1]--;
				last=2;
				ans+=4;
			}
			else
			{
				cnt[2]--;
				last=4;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
