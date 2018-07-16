#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		if(i)
			putchar(' ');
		printf("%d",a-!(a%2));
	}
	return 0;
}
