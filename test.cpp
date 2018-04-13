#include <cmath>
#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;
int main()
{
    char ch;
    FILE *fp = fopen("testtxt", "w");
    srand((unsigned int)time(NULL));
    for (int i = 1; i <= 1024; i++)
    {
        if (!(i % 16))
            fputc('\n', fp);
        else
        {
            ch = rand() % 62;
            if (ch < 10)
                ch += '0';
            else if (ch < 36)
                ch += 'a' - 10;
            else
                ch += 'A' - 36;
            fputc(ch, fp);
        }
    }
    fclose(fp);
    return 0;
}