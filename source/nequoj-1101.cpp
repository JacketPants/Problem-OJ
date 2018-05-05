#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
bool cmp(string x,string y)
{
    if(x.length()==y.length())
        return x>y;
    return x.length()<y.length();
}
string list[100];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>list[i];
    sort(list,list+n,cmp);
    for(int i=0;i<n;i++)
        cout<<list[i]<<endl;
    return 0;
}
