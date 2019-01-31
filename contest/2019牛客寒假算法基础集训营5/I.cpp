#include<iostream>
#include<cstring>
using namespace std;
char p[505][505];

int run(int x)
{
	int i=1,j=x,pos=0;//ÄæÊ±Õë 
	while(p[i][j]!='#')
	{
		if(p[i][j]=='\\')
		{
			if(pos==0)
			{
				pos=1;
			}
			else if(pos==1)
			{
				pos=0;
			}
			else if(pos==2)
			{
				pos=3;
			}
			else if(pos==3)
			{
				pos=2;
			}
		}
		else if(p[i][j]=='/')
		{
			if(pos==0)
			{
				pos=3;
			}
			else if(pos==1)
			{
				pos=2;
			}
			else if(pos==2)
			{
				pos=1;
			}
			else if(pos==3)
			{
				pos=0;
			}
		}
		if(pos==0)
		{
			i++;
		}
		else if(pos==1)
		{
			j++;
		}
		else if(pos==2)
		{
			i--;
		}
		else if(pos==3)
		{
			j--;
		}
	}
	if(pos==0)
		return j;
	return -1;
}

int main()
{
	int n,m;
	cin>>n>>m;
	memset(p,'#',sizeof p);
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
		{
			p[i][j]=getchar();
		}
	}
	for(int i=1;i<=m;i++)
	{
		printf("%d\n",run(i));
	}
	return 0;
}
/*
6 5
.....
/\.\\
.\/.\
\././
././.
.\...

*/
