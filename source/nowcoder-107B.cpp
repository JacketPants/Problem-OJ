#include <cstring>
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s, tem;
    char dir[26], cnt[26];
    int n, ans;
    bool isCan;
    while (cin >> s)
    {
        memset(dir, 0, sizeof dir);
        ans = 0;
        cin >> n;
        for (int i = 0; i < s.length(); i++)
            dir[s[i] - 'a']++;
        for (int i = 0; i < n; i++)
        {
            memset(cnt, 0, sizeof cnt);
            cin >> tem;
            for (int j = 0; j < tem.length(); j++)
                cnt[tem[j] - 'a']++;
            isCan = true;
            for (int j = 0; j < 26; j++)
                if (cnt[j] > dir[j])
                    isCan = false;
            if (isCan && ans < tem.length())
                ans = tem.length();
        }
        printf("%d\n", ans);
    }
    return 0;
}
/*
链接：https://www.nowcoder.com/acm/contest/107/B
来源：牛客网

masterblodpo
7
boogie
magnolia
punch
blood
master
inherent
phantom
ablderrivala
5
arrival
blade
runner
incendies
sicario
*/