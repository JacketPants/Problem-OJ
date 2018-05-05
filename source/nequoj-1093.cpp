#include<iostream>
#include<string>

using namespace std;

bool is(string s)
{
    int len=s.length();
    if(len%2)
        return false;
    else
        len/=2;
    for(int i=0;i<len;i++)
        if(s[len-1-i]!=s[len+i])
            return false;
    return true;
}

int main()
{
    int n;
    string s;
    cin>>n;
    while(n--)
    {
        cin>>s;
        while(is(s))
            s=s.substr(0,s.length()/2);
        cout<<s.length()<<endl;
    }
    return 0;
}
