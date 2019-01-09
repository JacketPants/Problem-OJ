/*
比赛时未写完，思路是：
由题目可知推论，一个数字n，如果其第一次出现位置为a_i，最后一次出现位置为a_j，则b_i到b_j之间的元素必定一样 

从左向右遍历a数组，设置变量last表示当前遇到的最后一次出现位置。
对于每次遍历，进行到i元素时，如果i>last，则令cnt++，之后寻找i元素的最后一次更新位置，并更新last

cnt为拐点数 
答案为2^拐点数 
时间复杂度为O(N^2) 
*/
#include<iostream>
#include<cstring>
using namespace std;
int l[200005];
bool u[200005]; 
int main()
{
	memset(u,-1,sizeof u);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%d",l+i);
	for(int i=0;i<n;i++)
	{
		if(u[i])
		{
			for(int j=n-1;j>i;j--)
			{
				if(l[i]==l[j])
				{
					for(int k=i;k<=j;k++)
						u[i]=false;
					break;
				}
			}
		}
	}
	return 0;
}
