/*
����ʱδд�꣬˼·�ǣ�
����Ŀ��֪���ۣ�һ������n��������һ�γ���λ��Ϊa_i�����һ�γ���λ��Ϊa_j����b_i��b_j֮���Ԫ�رض�һ�� 

�������ұ���a���飬���ñ���last��ʾ��ǰ���������һ�γ���λ�á�
����ÿ�α��������е�iԪ��ʱ�����i>last������cnt++��֮��Ѱ��iԪ�ص����һ�θ���λ�ã�������last

cntΪ�յ��� 
��Ϊ2^�յ��� 
ʱ�临�Ӷ�ΪO(N^2) 
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
