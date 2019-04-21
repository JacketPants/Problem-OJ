#include<iostream>

using namespace std;

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		if(n==0)
			cout<<0<<endl;
		else if(n==1)
			cout<<2<<endl;
		else
			cout<<n*(n-1)-1<<endl;
	}
	return 0;
}
/*
3
1 2
1 3
2 1
2 3
3 1
3 2
*/
/*
4
1 2
1 3
1 4
2 1
2 3
2 4
3 1
3 2
3 4
4 1
4 2
4 3
*/
