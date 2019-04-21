#include<iostream>

using namespace std;
int main()
{
	int t,n,m,y,tmp;
	double ans,p1,p2,t1,t2;
	cin>>t;
	while(t--)
	{
		p1=p2=t1=t2=0;
		scanf("%d%d%d",&n,&m,&y);
		p1=(double)n/(n+m);
		p2=(double)m/(n+m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&tmp);
			t1+=tmp;
		}
		t1/=n;
		for(int i=0;i<m;i++)
		{
			scanf("%d",&tmp);
			t2+=tmp;
		}
		t2/=m;
		ans=(p1*t1+p2*t2)/(1-p2);
//		cout<<ans<<endl;
		if(ans<=y)
			puts("Go");
		else
			puts("Wait"); 
	}
	return 0;
}
