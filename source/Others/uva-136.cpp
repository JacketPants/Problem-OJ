#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
long long list[3] = {2, 3, 5};
int main()
{
    long long tem, temb;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    set<long long> s;
    q.push(1);
    s.insert(1);
    for (int i = 1; i <= 1500; i++)
    {
        tem = q.top();
        q.pop();
        if (i == 1500)
            cout << "The 1500'th ugly number is " << tem << '.' << endl;
        for (long long j = 0; j < 3; j++)
        {
            temb = tem * list[j];
            if (!s.count(temb))
            {
                s.insert(temb);
                q.push(temb);
            }
        }
    }
    return 0;
}