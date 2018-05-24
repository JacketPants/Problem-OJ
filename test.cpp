#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    puts("c pointer style");
    char *ps1 = "hello";
    char *ps2 = "world.";
    puts("before");
    printf("%s %s\n", ps1, ps2);
    swap(ps1, ps2);
    puts("after");
    printf("%s %s\n", ps1, ps2);
    putchar('\n');

    puts("c array style");
    char s1[10];
    strcpy(s1, "hello");
    char s2[10];
    strcpy(s2, "world.");
    puts("before");
    printf("%s %s\n", s1, s2);
    for (int i = 0; s1[i] || s2[i]; i++)
        swap(s1[i], s2[i]);
    puts("after");
    printf("%s %s\n", s1, s2);
    puts("reverse");
    reverse(s1,s1+strlen(s1));
    reverse(s2,s2+strlen(s2));
    printf("%s %s\n", s1, s2);
    putchar('\n');

    puts("cpp style");
    string ss1, ss2;
    ss1 = "hello";
    ss2 = "world.";
    puts("before");
    cout << ss1 << ' ' << ss2 << endl;
    swap(ss1, ss2);
    puts("after");
    cout << ss1 << ' ' << ss2 << endl;
    puts("reverse");
    reverse(ss1.begin(),ss1.end());
    reverse(ss2.begin(),ss2.end());
    cout << ss1 << ' ' << ss2 << endl;
    return 0;
}
