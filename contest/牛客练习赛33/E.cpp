#include <bits/stdc++.h>


using namespace std;

const int N=1e5+777;
const int BASE=233;
const int MOD=1e9+7;

char s[N];
long long dHash[30][N],hsh[N];

long long GetHash(int id,int l,int r)
{
    return (dHash[id][r]-dHash[id][l-1]*hsh[r-l+1]%MOD+MOD)%MOD;
}
void Init(int n)
{
    hsh[0]=1;
    for(int i=1;i<=n;i++)
    {
        hsh[i]=hsh[i-1]*BASE%MOD;
        for(int j=0;j<26;j++)
            dHash[j][i]=(dHash[j][i-1]*BASE+(s[i]-'a'+j)%26)%MOD;
    }
}
int main()
{
    int n,q,x,y,l,tmp;
    long long ans;
    cin>>n>>s>>q;
    Init(n);
    while(q--)
    {
        ans=-1;
        scanf("%d%d%d",&x,&y,&l);
        tmp=abs(s[y]-s[x]);
        if(GetHash(0,y,y+l-1)==GetHash((s[y]-s[x]+26)%26,x,x+l-1))
            ans=min(tmp,26-tmp);
        printf("%lld\n",ans);
    }
    return 0;
}
/*
#define N 1000777
#define BASE 233
#define MOD 1000000007
*/