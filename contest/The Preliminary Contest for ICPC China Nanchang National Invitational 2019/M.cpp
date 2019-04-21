#include<iostream>
#include<cstring>
using namespace std;
char s[100010],t[100010];
int main()
{
	int n,len,lent;
	scanf("%s",s);
	scanf("%d",&n);
	len=strlen(s);
	for(int i=0;i<n;i++)
	{
		scanf("%s",t);
		lent=strlen(t);
		int p=len-1;
		while(lent && p>=0)
		{
			if(t[lent-1]==s[p--])
			{
				lent--;
			}
		}
		if(lent)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
/*
oiasdioashoao
100
ooo
*/
