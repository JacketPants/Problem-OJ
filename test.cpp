#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    bool isCan;
    string s;
    while (cin >> s)
    {
        isCan = true;
        stack<char> a;
        for (int i = 0; i < s.length() && isCan; i++)
        {
            if (s[i] == '(' || s[i] == '[')
                a.push(s[i]);
            else
            {
                if (a.empty() || (s[i] == ')' && a.top() == '[') || (s[i] == ']' && a.top() == '('))
                    isCan = false;
                else
                    a.pop();
            }
        }
        if (isCan && a.empty())
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}