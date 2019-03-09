#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define lowbit(x) x & -x
#define MAXN 1000010

using namespace std;

int mrand()
{
	return 10000*(rand()%10000)+rand();
}

int Tree[MAXN];
void add(int x, int value)
{
    for (int i = x; i <= MAXN; i += lowbit(i))
        Tree[i] += value;
}

int get(int x)
{
    int sum = 0;
    for (int i = x; i; i -= lowbit(i))
        sum += Tree[i];
    return sum;
}

int main()
{
	int t,n,m,a,b;
	cin>>t;
	while(t--)
	{
		memset(Tree,0,sizeof Tree);
		scanf("%d%d",&n,&m);
		int i,ans=-1;
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			if(a>b)
				swap(a,b);
			if(get(b)-get(a-1)!=0)
			{
				ans=i+1;
				break;
			}
			int tmp=mrand();
			add(a,tmp);
			add(b,-tmp);		
		}
		while(++i<m)
			scanf("%d%d",&a,&b);
		printf("%d\n",ans);
	}
	return 0;
} 
