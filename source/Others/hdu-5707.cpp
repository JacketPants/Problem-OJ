#include <iostream>
#include <string>

using namespace std;
int main()
{
    string a, b, c;
    int j, k;
    bool is;
    while (cin >> a >> b >> c)
    {
        j = k = 0;
        is = a.length() + b.length() == c.length();
        for (int i = 0; is && i < c.length(); i++)
            if (j < a.length() && a[j] == c[i])
                j++;
            else if (k < b.length() && b[k] == c[i])
                k++;
            else
                is = false;
        cout << (is ? "Yes\n" : "No\n");
    }
    return 0;
}
/*

abcdef

*/