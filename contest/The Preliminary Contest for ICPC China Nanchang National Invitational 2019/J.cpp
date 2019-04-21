#include<iostream>

using namespace std;

const int maxn = 100050;
int anc[maxn][64];
int dep[maxn*4];

void dfs(int root)
{
	static int Stack[maxn];
	int top = 0;
	dep[root] = 1;
	for(int i=0;i<maxh;i++)
		anc[root][i]=root;
	Stack[++top] = root;
	memcpy(head, info, sizeof head);
	while(top)
	{
		int x = Stack[top];
		if(x != root)
		{
			for(int i=1;i<maxh;i++)
			{
				int y = anc[x][i-1];
				anc[x][i] = anc[y][i-1];
			}
		}
		for(int &i=head[x];i;i=next[i])
		{
			int y = point[i];
			if(y != anc[x][0])
			{
				dep[y] = dep[x] + 1;
				anc[y][0] = x;
				Stack[++top] = y;
			}
		}
		while(top && head[Stack[top]] == 0)
			top--;
	}
}

void swim(int &x,int H)
{
	for(int i=0;H>0;i++)
	{
		if(H&1)
			x = anc[x][i];
		H/=2;
	}
}

int lca(int x,int y)
{
	int i;
	if(dep[x]>dep[y])
		swap(x,y);
	swim(y, dep[y] - dep[x]);
	if(x==y)
		return x;
	for(;;)
	{
		for(i=0;anc[x][i] != anc[y][i]; i++);
		if(i == 0)
			return anc[x][0];
		x = anc[x][i - 1];
		y = anc[y][i - 1];
	}
	return -1;
}

int main()
{
	
	return 0;
}
