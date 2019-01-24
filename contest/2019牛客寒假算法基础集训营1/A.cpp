#include<iostream>
#include<stack>
using namespace std;

stack<pair<long long,long long>> o;

int main()
{
    long long n,x,tmpa,tmpb;
    cin>>n>>x;
    while(n--)
    {
    	cin>>tmpa>>tmpb;
        o.emplace(pair<long long,long long>(tmpa,tmpb));
    }
    while(!o.empty())
    {
        switch (o.top().first)
        {
            case 1:
                x-=o.top().second;
                break;
            case 2:
                x+=o.top().second;
                break;
            case 3:
                x/=o.top().second;
                break;
            case 4:
                x*=o.top().second;
                break;
            default:
                break;
        }
        o.pop();
    }
    cout<<x<<endl;
    return 0;
}
