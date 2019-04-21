#include<iostream>
#include<cstring>
#include<bitset>
using namespace std;
char ss[1000500];
/*
bool b[1000000];
char ss[1000500];
int pow[6]={1,2,4,8,16,32};
*/
/*
inline int btoi(int f, int t)
{
	int ans=0, p=1;
	for(int i=0;i<6;i++)
//	for(int i=t-1;i>=f;i--)
	{
		if(b[f+i])
			ans+=p;
		p<<=1;
	}
	return ans;
}
*/

inline void out(int x)
{
    if (x > 9)
        out(x / 10);
    putchar(x % 10 + '0');
}

int main()
{
	int p,n,sum,ans,fi=63,tmp;
	char ch[3];
	p=0;
	while(~scanf("%s",ss))
	{
		n=strlen(ss);
		for(int i=0;i<n;i+=3)
		{
			ans=sum=0;
			sum|=int(ss[i]);
			sum|=int(ss[i+1]<<8);
			sum|=int(ss[i+2]<<16);
			
			for(int j = 0; j < 24; ++j) {
                ans = (ans << 1) | ((sum >> j) & 1);
            }
			printf("%d %d %d %d ", (ans >> 18) & 63, (ans >> 12) & 63, (ans >> 6) & 63, ans & 63);
			
//			else printf("%d %d %d %d", (ans >> 18) & 63, (ans >> 12) & 63, (ans >> 6) & 63, ans & 63);
		}
/*		for(int i=23;i>=0;i--)
		{
			printf("%d",sum);
			if((i+1)%6==0)
				putchar(' ');
		}
		
		putchar('\n');
*/		
	}
/*		
	for(int i=0;i<p;i++)
	{
		printf("%d",b[i]);
		if((i+1)%6==0)
			putchar(' ');
	}
		
	putchar('\n');
*/	
/*	
	for(int i=0;i<p;i+=6)
	{
		ans=0;
		for(int j=5;j>=0;j--)
		{
			if(b[i+j])
				ans|=pow[j];
		}
//			cout<<i<<' '<<min(i+6,p)<<endl;
		out(ans);
		putchar(' ');
//			cout<<endl;
	}
	*/
	return 0;
}
