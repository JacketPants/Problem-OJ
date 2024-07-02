#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s == "zero")
            cout << "ling\n";
        else if (s == "one")
            cout << "yi\n";
        else if (s == "two")
            cout << "er\n";
        else if (s == "three")
            cout << "san\n";
        else if (s == "four")
            cout << "si\n";
        else if (s == "five")
            cout << "wu\n";
        else if (s == "six")
            cout << "liu\n";
        else if (s == "seven")
            cout << "qi\n";
        else if (s == "eight")
            cout << "ba\n";
        else if (s == "nine")
            cout << "jiu\n";
        else if (s == "ten")
            cout << "shi\n";
    }

    return 0;
}