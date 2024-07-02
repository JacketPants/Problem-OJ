#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double n,p,k;
    while(cin>>n>>p)
    {
        k=pow(p,1/n);
        cout<<floor(k+0.5)<<endl;
    }
    return 0;
}