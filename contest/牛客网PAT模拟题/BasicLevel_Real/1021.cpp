#include <iostream>
using namespace std;
int p[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int to[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
    int n;
    cin >> n;
    bool flag = true;
    while (n--)
    {
        int sum = 0;
        char num[18];
        cin >> num;
        for (int i = 0; i < 17; i++)
        {
            if (num[i] == 'X')
            {
                cout << num << endl;
                flag = false;
                break;
            }
            sum += p[i] * (num[i] - '0');
        }
        if (to[sum % 11] != num[17])
        {
            cout << num << endl;
            flag = false;
        }
    }
    if (flag)
        cout << "All passed\n";
    return 0;
}