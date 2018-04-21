#include <cstdlib>
#include <iostream>
using namespace std;
int main()
{
    char s[1024];
    for (int i = 3; i < 1000; i += 3)
    {
        itoa(i, s, 2);
        printf("%s\n", s);
    }
    return 0;
}