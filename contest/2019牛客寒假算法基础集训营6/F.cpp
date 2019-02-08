#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int cnt[3]={0},tmp[3];
string to[3]={"R","P","S"};
char ans[1<<21];
string Create(int n,int x)
{
	if(n)
	{
		string l=Create(n-1,x),r=Create(n-1,(x+1)%3);
		if(l<r)
			return l+r;
		return r+l;
	}
	return string(to[x]);
}
int main()
{
	string ans;
	int a[25],b[25];
	scanf("%d%d%d",cnt,cnt+1,cnt+2);
	int sum=cnt[0]+cnt[1]+cnt[2],n=log2(sum);
	for(int i=0;i<3;i++)
	{
		a[i]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
				b[j]=a[j];
			for(int j=0;j<3;j++)
				a[(j+1)%3]+=b[j];
		}
		bool flag=false;
		for(int i=0;i<2;i++)
			if(a[i]!=cnt[i])
				flag=true;
		if(flag)
			continue;
		tmp[0]=cnt[0];
		tmp[1]=cnt[1];
		tmp[2]=cnt[2];
		ans=Create(n,i);
		break;
	}
	if(ans.empty())
		puts("IMPOSSIBLE");
	else
		puts(ans.c_str());
	return 0;
}
