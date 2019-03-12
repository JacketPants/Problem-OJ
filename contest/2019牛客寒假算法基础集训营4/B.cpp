#include<iostream>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	if(n==1 && m==2)
	{
		puts("RL");
	}
	else if(n==2 && m==1)
	{
		puts("DU");
	}
	else if(n==1||m==1)
	{
		puts("-1");
	}
	else if(n%2==0)
	{
		for(int i=1;i<n;i++)
			putchar('D');
		putchar('R');
		for(int i=0;i<n;i+=2)
		{
			for(int i=2;i<m;i++)
				putchar('R');
			putchar('U');
			for(int i=2;i<m;i++)
				putchar('L');
			if(i+2==n)
				putchar('L');
			else
				putchar('U');
		}
	}
	else if(m%2==0)
	{
		for(int i=1;i<m;i++)
			putchar('R');
		putchar('D');
		for(int i=0;i<m;i+=2)
		{
			for(int i=2;i<n;i++)
				putchar('D');
			putchar('L');
			for(int i=2;i<n;i++)
				putchar('U');
			if(i+2==m)
				putchar('U');
			else
				putchar('L');
		}
	}
	else
	{
		puts("-1");
	}
	return 0;
 } 
