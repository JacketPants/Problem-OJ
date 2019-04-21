#include<iostream>
#include<cstring>
using namespace std;
char s[100010],t[100010];
int to[100010][30];/* 1 is s's 0 */
int pos[30];
int main()
{
	int n,len,lent;
	scanf("%s",s+1);
	len=strlen(s+1);
	memset(pos,-1,sizeof pos);
	memset(to,-1,sizeof to);
	
	for(int i=len;i>=0;i--)
	{
		for(int j=0;j<26;j++)
		{
			to[i][j]=pos[j];
		}
		if(i)
			pos[s[i]-'a']=i;
	}
/*	
	for(int i=0;i<)
*/	
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
	{
		bool flag=true;
		scanf("%s",t);
		lent=strlen(t);
		int p=0;
		for(int i=0;i<lent;i++)
		{
			if(to[p][t[i]-'a']!=-1)
			{
				p=to[p][t[i]-'a'];
//				cout<<t[i]<<' '<<p<<endl;
			}
			else
			{
				flag=false;
				break;
			}
		}
		if(flag)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
/*
oiasd ioash oao
oiasdioashoao
7
ooo
oia
o
dioooo
dhooa
asoish
sho
*/
