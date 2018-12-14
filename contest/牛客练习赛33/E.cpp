#include<iostream>
#include<cstring>
#define MAXN 100005
#define MOD 1000000007
using namespace std;
char s[MAXN],hsh[30][MAXN];
int main()
{
    int n,q,l,r,len,ans;
    cin>>n>>s>>q;
    for(int i=0;i<26;i++)
        for(int j=0;j<n;j++)
            hsh[i][j] = (s[j]-'a'+i)%26+'a';
    while(q--)
    {
        ans=-1;
        scanf("%d%d%d",&l,&r,&len);
        l--;r--;
        for(int i=0;i<26;i++)
        {
            if(!strncmp(s+r,hsh[i]+l,len))
            {
                ans=min(i,26-i);
                break;
            }
        }
        printf("%d\n",ans);
    }    
    return 0;
}
