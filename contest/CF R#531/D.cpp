#include<iostream>
using namespace std;
char str[500005];
int cnt[3]={0};
bool vis[500005]={0};
int main()
{
	int n;
	cin>>n>>str;
	int m=n/3;
	for(int i=0;i<n;i++)
		cnt[str[i]-'0']++;
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			if(str[i]=='2' && cnt[2]>m && cnt[0]<m)
			{
				cnt[2]--;
				cnt[0]++;
				str[i]='0';
			}
			else if(str[i]=='2' && cnt[2]>m && cnt[1]<m)
			{
				cnt[2]--;
				cnt[1]++;
				str[i]='1';
			}
			else if(str[i]=='1' && cnt[1]>m && cnt[0]<m)
			{
				cnt[1]--;
				cnt[0]++;
				str[i]='0';
			}
			else
			{
				vis[i]=false;
			}
		}
	}
	for(int i=n-1;i>=0;i--)
	{
		if(!vis[i])
		{
			vis[i]=true;
			if(str[i]=='0' && cnt[0]>m && cnt[2]<m)
			{
				cnt[0]--;
				cnt[2]++;
				str[i]='2';
			}
			else if(str[i]=='0' && cnt[0]>m && cnt[1]<m)
			{
				cnt[0]--;
				cnt[1]++;
				str[i]='1';
			}
			else if(str[i]=='1' && cnt[1]>m && cnt[2]<m)
			{
				cnt[1]--;
				cnt[2]++;
				str[i]='2';
			}
			else
			{
				vis[i]=false;
			}
		}
	}
	puts(str);
	return 0;
}
