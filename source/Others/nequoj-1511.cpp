#include<iostream>

using namespace std;
int list[1010];
int dp[1010];
int m,k;
int Search(int m)
{
    int minn=dp[m-1];
    for(int i=2;i<=k;i++)
        minn=min(dp[m-i],minn);
    return minn;
}
int main()
{
    while(cin>>m>>k)
    {
        list[0]=0;
        for(int i=1;i<=m;i++)
        {
            cin>>list[i];
            dp[i]=list[i];
        }
        dp[0]=0;
        for(int i=k+1;i<=m;i++)
        {
            dp[i]=list[i]+Search(i);
        }
        cout<<dp[m]<<endl;
    }
    return 0;
}
