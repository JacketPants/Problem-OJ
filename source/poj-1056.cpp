#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#define CHARSET 26
#define BASE 'a'
#define MAX_NODE 5000
using namespace std;

int main()
{
    int id = 0;
    vector<string> list;
    map<string, int> pre;
    string s;
    while (cin >> s)
    {
        id++;
        bool ok = false;
        list.clear();
        pre.clear();
        while (s != "9")
        {
            list.push_back(s);
            cin >> s;
        }
        for (int i = 0; i < list.size(); i++)
            for (int j = list[i].length() - 1; j; j--)
                pre[list[i].substr(0, j)]++;
        for (int i = 0; i < list.size(); i++)
        {
            ok = pre[list[i]];
            if (ok)
                break;
        }
        if (ok)
            printf("Set %d is not immediately decodable\n", id);
        else
            printf("Set %d is immediately decodable\n", id);
    }
    return 0;
}