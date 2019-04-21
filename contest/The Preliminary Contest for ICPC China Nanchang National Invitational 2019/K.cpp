#include <iostream>

using namespace std;

int t,n,q,l,r,len,ans,cnt;
int a[100050];
int main(){
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",a+i);
		}
		scanf("%d",&q);
		for(int i=0;i<q;i++)
		{
			ans=0;
			scanf("%d%d",&l,&r);
			len=r-l+1;
			if(len%4==0)
			{
				puts("!");
				ans=0;
			}
			else if(len%2==0)
			{
				puts("@");
				for(int j=l;j<=r;j+=4)
				{
					ans^=a[j];
//					if(j+1<=r)
						ans^=a[j+1];
				}
			}
			else
			{
				if(((len+1)/2)%2==1)
				{
					puts("#");
					for(int j=l;j<=r;j+=4)
					{
						ans^=a[j];
					}
				}
				else
				{
					puts("$");
					for(int j=l+1;j<=r;j+=4)
					{
						ans^=a[j];
					}
				}				
			}

			cout<<ans<<endl;
		}
	}
	
	
	
	return 0;
}
