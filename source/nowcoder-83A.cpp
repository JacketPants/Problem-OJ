#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;
int main()
{
    char s[10000];
    cin >> s;
    stringstream ss;
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        if (s[i] == '(' || s[i] == ')' || s[i] == ',')
            s[i] = ' ';
    ss << s;
    while(!ss.eof())
        ss >> s;
    cout << s << endl;
    return 0;
}