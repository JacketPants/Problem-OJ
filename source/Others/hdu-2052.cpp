#include<iostream>
using namespace std;
int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		putchar('+');
		for(int i=0;i<m;i++)
			putchar('-');
		putchar('+');
		putchar('\n');
		for(int i=0;i<n;i++)
		{
			putchar('|');
			for(int j=0;j<m;j++)
				putchar(' ');
			putchar('|');
			putchar('\n');
		}
		putchar('+');
		for(int i=0;i<m;i++)
			putchar('-');
		putchar('+');
		putchar('\n');
		putchar('\n');
	}
	return 0;
} 