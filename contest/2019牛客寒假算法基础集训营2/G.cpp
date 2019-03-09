#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string s,t;
int lcs()
{
    int dp[101][101]={0};
    for(int i=0;i<=s.length();i++)
    {
        for(int j=0;j<=t.length();j++)
        {
            if(!i||!j)
                dp[i][j]=0;
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[s.length()][t.length()];
}
int main()
{
    cin>>s>>t;
    int ls=s.length(),lt=t.length();
    int l=lcs();
    if(abs(ls-lt)>2)
    {
        puts("NO");
    }
    else
	{
		if(abs(ls-lt)==2)
		{
			if(abs(ls-l)==2)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
		else if(ls-lt==1)
		{
			if(ls-l==2)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
		else if(ls-lt==0)
		{
			if(ls-l==2)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
		else if(ls-lt==-1)
		{
			if(ls-l==1)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
		else if(ls-lt==-2)
		{
			if(ls-l==0)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
	}
    return 0;
}
