#include<iostream>

using namespace std;

long long PowMod(long long a, long long i, long long n = 1)
{
    if(i==0)
        return 1 % n;
    long long ans = PowMod(a, i >> 1, n);
    ans = ans * ans % n;
    if(i&1)
        ans = ans * a % n;
    return ans;
}

int main()
{
    int t,a,n,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>n>>b;
        cout<<PowMod(a,n,b)<<endl;
    }
    return 0;
}