#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;
#define INF 0xfffffff
#define min(a,b) (a<b?a:b)
#define maxn 100005

struct Edge
{
	int index,x;
	Edge(int index=0, int x=0)
	{
		this->index=index;
		this->x=x;
	}
};

int m, n, Time, ans;
int dfn[maxn], low[maxn], Father[maxn], bridge[maxn];
vector<Edge> G[maxn];
 
void init()
{
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(bridge, 0, sizeof(bridge));
    memset(Father, 0, sizeof(Father));
    Time = ans = 0;
 
    for(int i=0; i<=n; i++)
        G[i].clear();
}
 
void Tarjan(int u,int fa)
{
    dfn[u] = low[u] = ++Time;
    Father[u] = fa;
    int len = G[u].size(), v;
 
    for(int i=0; i<len; i++)
    {
        v = G[u][i].index;
 
        if( !low[v] )
        {
            Tarjan(v, u);
            low[u] = min(low[u], low[v]);
 
            if(dfn[u] < low[v])
            {
                bridge[v] ++;
                ans ++;
            }
        }
        else if(v != fa)
        {
            low[u] = min(low[u], dfn[v]);
 
            if(dfn[u] < low[v])
            {
                bridge[v] ++;
                ans --;
            }
        }
 
    }
}
void Lca(int a,int b)
{
    if(a == b)
        return ;
 
    if(dfn[a] > dfn[b])
    {
        if( bridge[a] == 1)
        {
            bridge[a] = 0;
            ans --;
        }
        Lca(Father[a], b);
    }
    else
    {
        if(bridge[b] == 1)
        {
            bridge[b] = 0;
            ans --;
        }
        Lca(a, Father[b]);
    }
}

int main()
{
    while(~scanf("%d%d",&n, &m))
    {
        int Q, a, b, c;
        init();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            G[a].push_back(Edge(b,c));
            G[b].push_back(Edge(a,c));
        }
        cout<<"!"<<endl;
        Tarjan(1, 0);
    //    printf("%d\n", ans);
        while(Q --)
        {
            scanf("%d%d%d",&a, &b, &c);
            Lca(a, b);
            printf("%d\n", ans);
        }
    }
    return 0;
}
/*
 
4 4
1 2
2 1
2 3
1 4
2
1 2
3 4
 
  */


