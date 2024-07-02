#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int longestCommonSubstring_n2_1(const string& str1, const string& str2)
{
    size_t size1 = str1.size();
    size_t size2 = str2.size();
    if (size1 == 0 || size2 == 0) return 0;

    // the start position of substring in original string
    int start1 = -1;
    int start2 = -1;
    // the longest length of common substring
    int longest = 0;

    // record how many comparisons the solution did;
    // it can be used to know which algorithm is better
    int comparisons = 0;

    for (int i = 0; i < size1; ++i)
    {
        int m = i;
        int n = 0;
        int length = 0;
        while(m < size1 && n < size2)
        {
            ++comparisons;
            if (str1[m] != str2[n])
            {
                length = 0;
            }
            else
            {
                ++length;
                if (longest < length)
                {
                    longest = length;
                    start1 = m-longest+1;
                    start2 = n-longest+1;
                }
            }

            ++m;
            ++n;
        }
    }

    // shift string2 to find the longest common substring
    for (int j = 1; j < size2; ++j)
    {
        int m = 0;
        int n = j;
        int length = 0;
        while(m < size1 && n < size2)
        {
            ++comparisons;
            if (str1[m] != str2[n])
            {
                length = 0;
            }
            else
            {
                ++length;
                if (longest < length)
                {
                    longest = length;
                    start1 = m-longest+1;
                    start2 = n-longest+1;
                }
            }

            ++m;
            ++n;
        }
    }
    return longest;
}

int main() {
    int n;
    string a,b;
    int dp[105][105];
    
    cin >> n;
    for (int _=0;_<n;_++)
    {
        memset(dp,0,sizeof(dp));
        cin>>a>>b;
        int maxsub = longestCommonSubstring_n2_1(a,b);
        int ans = a.size()+b.size()-maxsub;
        cout<<ans<<"\n";
    }
    return 0;
}
// abc
// adc
// abcdc
// cababacbc