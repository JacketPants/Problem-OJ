#include <iostream>
#include <string>
using namespace std;
int main()
{
    int t, n;
    string tema, maxa;
    int temb, maxb;
    cin >> t;
    while (t--)
    {
        cin >> n >> maxa >> maxb;
        for (int i = 1; i < n; i++)
        {
            cin >> tema >> temb;
            if (temb > maxb)
            {
                maxb = temb;
                maxa = tema;
            }
        }
        cout << maxa << endl;
    }
    return 0;
}