#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> list;
int main()
{
    int n,m,tmp;
	long long sum=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        list.push_back(tmp);
    }
    sort(list.begin(),list.end());
    for(int i=0;i<n;i++)
    {
        if(list[i]<=sum+1)
        {
            sum+=list[i];
        }
    }
    if(sum<m || list[0]!=1)
        puts("NO");
    else
        puts("YES");
    return 0;
}
