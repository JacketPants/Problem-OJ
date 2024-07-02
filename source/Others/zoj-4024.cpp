#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int t, n, a, b;
    bool up, is, isUp, isDown;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%d", &b);
        is = up = true;
        isUp = isDown = false;
        for (int i = 1; i < n; i++)
        {
            scanf("%d", &a);
            if (up)
            {
                if (!(b < a))
                {
                    up = false;
                    isDown = true;
                }
                else
                    isUp = true;
            }
            else
            {
                if (!(b > a))
                    is = false;
            }
            b = a;
        }
        if (is && isUp && isDown)
        {
            puts("Yes");
        }
        else
            puts("No");
    }
    return 0;
}
/*
153 - The 15th Zhejiang Provincial Collegiate Programming Contest Sponsored by TuSimple - A
Peak
Time Limit: 1 Second      Memory Limit: 65536 KB
A sequence of $n$ integers $a_1, a_2, \dots, a_n$ is called a peak, if and only if there exists exactly one integer $k$ such that $1 < k < n$, and $a_i < a_{i+1}$ for all $1 \le i < k$, and $a_{i-1} > a_i$ for all $k < i \le n$.

Given an integer sequence, please tell us if it's a peak or not.

Input
There are multiple test cases. The first line of the input contains an integer $T$, indicating the number of test cases. For each test case:

The first line contains an integer $n$ ($3 \le n \le 10^5$), indicating the length of the sequence.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 2 \times 10^9$), indicating the integer sequence.

It's guaranteed that the sum of $n$ in all test cases won't exceed $10^6$.

Output
For each test case output one line. If the given integer sequence is a peak, output "Yes" (without quotes), otherwise output "No" (without quotes).

Sample Input
7
5
1 5 7 3 2
5
1 2 1 2 1
4
1 2 3 4
4
4 3 2 1
3
1 2 1
3
2 1 2
5
1 2 3 1 2
*/