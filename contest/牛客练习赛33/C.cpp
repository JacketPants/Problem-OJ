#include<iostream>
#include<set>
#include<map>
#include<string>
using namespace std;
string s;
set<int> rare;
map<char,int> num;
int main()
{
    for(int i=0;i<1000;i++)
        if(i%8==0)
            rare.insert(i);
    int t;
    cin>>t;
    while(t--)
    {
        num.clear();
        cin>>s;
        for(auto &ch:s) {
            num[ch]++;
        }
        for(auto it=rare.rbegin();it!=rare.rend();it++)
        {
            int tmp=*it;
        }
    }
    return 0;
}
/*
000
875
750
625
500
375
250
125
*/
