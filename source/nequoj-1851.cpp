#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>

using namespace std;
map<int,int> list;
vector<int> v;
//pair<int,int> g[100000];
int g[100010];
int main()
{
    int t,n,q,ans,k,tem;
    cin>>t;
    while(t--)
    {
        list.clear();
        v.clear();
        ans=0;
        cin>>n>>q;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tem);
            if(!list[tem])
                v.push_back(tem);
            list[tem]++;
        }
        sort(v.begin(),v.end());
//        for(int i=0;i<v.size();i++)
//            cout<<v[i]<<endl;

/*
        list[n]=0x3f3f3f3f;
        for(int i=1;i<=n;i++)
        {
            if(list[i]-list[i-1]!=1)
            {
                g[ans++]=i;
            }
        }*/
        for(int i=0;i<v.size();i++)
        {
            //cout<<'!'<<v[i];
            while(list[v[i]])
            {
                list[v[i]]=0;
                int j;
                for(j=i+1;list[v[j]]&&v[j]-v[j-1]==1&&j<v.size();j++)
                {
                    //list[v[i]]=0;
                    list[v[j]]=0;
                }
                g[ans++]=v[j-1];
            }
            //cout<<'?'<<v[i]<<endl;
        }
//        cout<<ans<<endl;
        sort(g,g+ans);
        for(int i=0;i<q;i++)
        {
            scanf("%d",&k);
            printf("%d ",ans-(upper_bound(g,g+ans,k)-g));
        }
        putchar('\n');
    }
    return 0;
}
