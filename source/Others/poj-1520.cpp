#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<bool> sw;
vector<string> str;
vector<int> num;

bool IsNum(string s)
{
    if (s[0] == '-' || (s[0] >= '0' && s[0] <= '9'))
        return true;
    return false;
}
string ToLower(string s)
{
    string ans;
    for (int i = 0; i < s.length(); i++)
        if (s[i] >= 'A' && s[i] <= 'Z')
            ans.push_back(s[i] + 32);
        else
            ans.push_back(s[i]);
    return ans;
}
bool cmp(string a, string b)
{
    return ToLower(a) < ToLower(b);
}
int main()
{
    string s;
    char end;
    int a, b;
    while (cin >> s && s != ".")
    {
        a = b = 0;
        sw.clear();
        str.clear();
        num.clear();
        do
        {
            end = s[s.size() - 1];
            s.erase(s.size() - 1);
            if (IsNum(s))
            {
                sw.push_back(true);
                num.push_back(atoi(s.c_str()));
            }
            else
            {
                sw.push_back(false);
                str.push_back(s);
            }
        } while (end != '.' && cin >> s);
        sort(num.begin(), num.end());
        sort(str.begin(), str.end(), cmp);
        for (int i = 0; i < sw.size(); i++)
            if (sw[i])
                cout << num[a++] << (i == sw.size() - 1 ? ".\n" : ", ");
            else
                cout << str[b++] << (i == sw.size() - 1 ? ".\n" : ", ");
    }
    return 0;
}