#include<iostream>

using namespace std;

int main()
{
    int score,n,ans=0;
    cin>>n;
    while(n--)
    {
        cin>>score;
        if(score<60)
            ans+=400;
    }
    cout<<ans<<endl;
    return 0;
}