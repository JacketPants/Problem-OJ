#include<iostream>
#include<cstdio>
using namespace std;
int list[16]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768};
int tempMap=0;
void filp(int i, int j)
{
	tempMap^=list[i*4+j];
	for(int k=0;k<4;k++)
		tempMap^=list[i*4+k];
	for(int k=0;k<4;k++)
		tempMap^=list[k*4+j];
}
int main()
{
	int temp,mymap=0,count,ans=0x3f3f3f3f,tempAns;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			mymap|=getchar()=='-'?list[i*4+j]:0;
		getchar();
	}
	for(int i=0;i<65536;i++)
	{
		temp=i;
		tempMap=mymap;
		count=0;
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				if(temp%2)
				{
					filp(j,k);
					count++;
				}
				temp/=2;
			}
		}
		if(tempMap==0xFFFF && count<ans)
		{
			ans=count;
			tempAns=i;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=4;j++)
		{
			if(tempAns%2)
				printf("%d %d\n",i,j);
			tempAns/=2;
		}
	return 0;
}
