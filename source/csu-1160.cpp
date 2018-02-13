#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> list;
	long long n;
	while(cin>>n)
	{
		list.clear();
		for(int i=0;n;n/=16)
			list.push_back(n%16);
		printf("0x");
		if(list.size()<8)
			for(int i=0;i<8-list.size();i++)
				putchar('0');
		for(int i=list.size()-1;i>=0;i--)
			if(list[i]<10)
				putchar(list[i]+'0');
			else
				putchar(list[i]-10+'A');
		putchar('\n');
	}
	return 0;
} 
