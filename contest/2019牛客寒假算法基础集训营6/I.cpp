#include<iostream>
#include<string>
#include<stack>
using namespace std;
string str;
stack<char> st;
int main()
{
	cin>>str;
	int ans=0;
	for(int i=0;i<str.length();i++)
	{
		if(!st.empty()&&st.top()==str[i])
		{
			ans+=10;
			st.pop();
		}
		else
			st.push(str[i]);
	}
	ans+=st.size()/2*5;
	cout<<ans;
	return 0;
}
