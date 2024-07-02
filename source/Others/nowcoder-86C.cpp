#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s,list[] = {"algorithm", "bitset", "cctype", "cerrno", "clocale", "cmath", "complex", "cstdio", "cstdlib", "cstring", "ctime", "deque", "exception", "fstream", "functional", "limits", "list", "map", "iomanip", "ios", "iosfwd", "iostream", "istream", "ostream", "queue", "set", "sstream", "stack", "stdexcept", "streambuf", "string", "utility", "vector", "cwchar", "cwctype"};
    int t;
    bool isQian;
    cin >> t;
    while(t--)
    {
        isQian = false;
        cin >> s;
        for (int i = 0; i < 35;i++)
            if(list[i]==s)
                isQian = true;
        if(isQian)
            cout << "Qian\n";
        else
        {
            cout << "Kun\n";
        }
    }
    return 0;
}