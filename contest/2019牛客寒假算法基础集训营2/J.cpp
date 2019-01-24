#include<iostream>
#include<algorithm>
using namespace std;
pair<int,int> a[100005];
int main()
{
    int n,sum=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].second);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i].first);
    }
    sort(a,a+n);
    bool isYes=true;
    for(int i=0;i<n;i++)
    {
        sum+=a[i].second;
        if(sum>a[i].first)
        {
            isYes=false;
            break;
        }
        sum+=2;
    }
    if(isYes)
        puts("YES");
    else
        puts("NO");
    return 0;
}