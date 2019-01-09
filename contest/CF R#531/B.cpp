#include<iostream>
#include<cstring>

using namespace std;
int list[5005],nxt[5005],ans[5005],color[5005];
int main()
{
	bool isYes=true;
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>list[i];
	memset(nxt,0,sizeof nxt);
	memset(color,0,sizeof color);
	for(int i=0;i<n;i++)
	{
		if(nxt[list[i]]+1>k)
		{
			isYes=false;
			break;
		}			
		ans[i]=nxt[list[i]]+1;
		color[ans[i]]++;
		nxt[list[i]]++;
	}
	for(int i=1;i<=k;i++)
	{
		if(color[i])
			continue;
		int p=0;
		while(color[ans[p]]==1 && p<=k)
			p++;
		if(p>k)
		{
			isYes=false;
			break;
		}
		color[ans[p]]--;
		ans[p]=i;
		color[i]++;
	}
	if(isYes)
	{
		puts("YES");
		for(int i=0;i<n;i++)
			printf("%d%c",ans[i],i==(n-1)?'\n':' ');
	}
	else
	{
		puts("NO");
	}
	return 0;
}
