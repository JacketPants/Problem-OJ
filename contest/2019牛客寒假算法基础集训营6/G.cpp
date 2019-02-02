#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

long long slove(long long a,long long b)
{
	long long tmp=1;
	for(long long i=a^b;i>=tmp;tmp<<=1);
	return a|b|tmp-1;
}

int main()
{
	long long a,b,out;
	int la,lb;
	char sa[100],sb[100],ans[100];
	while(~scanf("%lld%lld",&a,&b))
	{
		printf("%lld\n",slove(a,b));
		/*
		out=0;
		itoa(a,sa,2);
		itoa(b,sb,2);
		la=strlen(sa);
		lb=strlen(sb);
		strrev(sa);
		strrev(sb);
		while(la!=lb)
		{
			if(la<lb)
			{
				sa[la++]='0';
			}
			else
			{
				sb[lb++]='0';
			}
		}
		sb[lb]=sa[la]='\0';
		strrev(sa);
		strrev(sb);
		for(int i=0;i<la;i++)
		{
			if(sa[i]==sb[i])
			{
				ans[i]=sa[i];
			}
			else
			{
				for(int j=i;j<la;j++)
				{
					ans[j]='1';
				}
				break;
			}
		}
		ans[la]='\0';
		for(int i=0;i<la;i++)
		{
			out<<=1;
			out|=ans[i]-'0';
		}
		printf("%lld\n",out);
//		puts(ans);
		*/
	}
	return 0;
}
