#include <iostream>
#include <string>
using namespace std;
string str;
int main()
{
    int c = 0, n = 0, s = 0, d = 0;
    getline(cin, str);
    for (auto &th : str)
        if(th<='9'&&th>='0')
            n++;
        else if(th<='z'&&th>='a')
            c++;
        else if(th<='Z'&&th>='A')
            c++;
        else if(th == ' ')
            s++;
        else
            d++;
    printf("%d %d %d %d", c, n, s, d);
    return 0;
}
