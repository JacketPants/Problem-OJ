#include <cstdio>
#include <cstring>
#include <cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=10000;
int list[N];
int Judge (int n)
{
	int m;
	while (n)
	{
		m=n%10;
		if (m%2==1)
			return 0;
		n=n/10;
	}
	return 1;
}
int main()
{
	int i,cnt=0;
	int low,mid,high,t,n;
	for (i=1;i<N;i++)
	{
		if (i%2==0)
		{
			if (Judge(i))
				list[cnt++]=i;
		}
	}
	for(int i=0;i<cnt;i++)
		cout<<list[i]<<endl; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		low=0;
		high=cnt-1;
		while (low<=high)
		{
			mid=(low+high)/2;
			if (n==list[mid])
				break;
			else if (n>list[mid])
				low=mid+1;
			else if (n<list[mid])
				high=mid-1;
		}
		printf("%d\n",min(abs(n-list[mid]),abs(n-list[mid-1])));
	 }
	 return 0;
}
