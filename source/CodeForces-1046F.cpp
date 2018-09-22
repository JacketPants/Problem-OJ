#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int list[200005];
int main()
{
    int n, x, f, cnt = 0;
    long long fee = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", list + i);
    scanf("%d%d", &x, &f);
    for (int i = 0; i < n; i++)
    {
        // if (list[i] > x && list[i] < x * 2 + f)
        //     fee += f;
        // else
        if (list[i] > x)
            fee += ceil((double)(list[i] - x) / (x + f)) * f;
        // while (list[i] > x)
        // {
        //     list[i] -= min(x, list[i] - x) + f;
        //     fee += f;
        // }
    }
    cout << fee << endl;
    return 0;
}
/*
4
14 15 7 5
6 2
13 1
14 1
15 2
16 2
22
y=6+x*(2+6)
x=(y-6)/(2+6)
*/