#include<iostream>

using namespace std;
char f[110][110];
char t[1100][1100];
int main()
{
	int n,m,k,x,y;
	char ch;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		y=x=1;
		for(int i=1;i<=n;i++)
		{
			getchar();
			for(int j=1;j<=m;j++)
			{
				ch=getchar();
				for(int xi=0;xi<k;xi++)
				{
					for(int yi=0;yi<k;yi++)
					{
						t[x+xi][y+yi]=ch;
					}
				}
				y+=k;
				if(y>m*k)
				{
					y=1;
					x+=k;
				}
			}
		}
		for(int i=1;i<=n*k;i++)
		{
			for(int j=1;j<=m*k;j++)
			{
				putchar(t[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
 } 
 /*
4 4 3
abca
*(*)
..,,
qpqp
 */
