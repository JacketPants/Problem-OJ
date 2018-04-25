#include<bits/stdc++.h>  
using namespace std;  
#define ll long long  
const int maxn=200005;  
const ll mod=10000007;  
vector<int>G[maxn];  
ll a[maxn],ans=0;  
bool vis[maxn];  
void dfs(int s)  
{  
    ll k=1;vis[s]=1;  
    for(int i=0;i<G[s].size();i++)  
    {  
        int to=G[s][i];  
        if(vis[to])continue;  
        dfs(to);  
        k=k*(a[to]+1)%mod;  
    }  
    a[s]=k%mod;  
}  
int main()  
{  
    int n;scanf("%d",&n);  
    for(int i=1;i<n;i++)  
    {  
        int x,y;scanf("%d%d",&x,&y);  
        G[x].push_back(y);  
        G[y].push_back(x);  
    }  
    dfs(1);  
    for(int i=1;i<=n;i++)ans=(ans+a[i])%mod;  
    printf("%lld\n",ans);  
    return 0;  
}  
