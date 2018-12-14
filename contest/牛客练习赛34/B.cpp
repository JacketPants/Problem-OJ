#include<iostream>

using namespace std;
int list[100005];
int main()
{
    long long sum=0;
    int n,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",list+i);
        sum+=list[i];
    }
    for(int i=0;i<n;i++)
        if(sum-list[i]*2==0)
            ans++;
    cout<<(ans?ans:-1)<<endl;
    return 0;
}