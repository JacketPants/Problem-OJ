#include<bits/stdc++.h>

using namespace std;
int a[5000005]={0},b[50]={0};
int main()
{
	int n,sum=0,sumb=0x3f3f3f3f,ansb=0,p=0,tmp,tmpb,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
		int j=0;
		tmp=a[i];
		while(tmp)
		{
			b[j++]+=(tmp&1);
			tmp>>=1;
		}
	}
	for(int i=0;i<n;i++)
	{
		int j=0;
		tmp=a[i];
		tmpb=0;
		while(tmp)
		{
			if(tmp&1 && b[j]==1)
			{
				tmpb+=1<<j;
			}
			tmp>>=1;
			j++;
		}
		if(tmpb<ansb)
		{
			p=i;
			ansb=tmpb;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i!=p)
			ans|=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
