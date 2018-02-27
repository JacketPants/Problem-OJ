#include<stdio.h>
int main()
{
	char ch;
	int t,ans,cnt;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		ans=cnt=0;
		ch=getchar();
		while(ch!='\n')
		{
			if(ch=='A')cnt++;
			else cnt=0;
			ans=ans<cnt?cnt:ans;
			ch=getchar();
		}
		for(int i=0;i<=ans;i++) putchar('A');
		putchar('\n');
	}
	return 0;
}