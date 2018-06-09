#include <iostream>

using namespace std;

int main()
{
    int t;
    int id, prob;
    char team[20], s[20];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%s%d%s", &id, team, &prob, s);
        printf("%3d|%-16s|%4d|", id, team, prob);
        if (s[0] == 'R')
        {
            scanf("%d", &id);
            for (int i = 0; i < id; i++)
                s[i] = 'X';
            s[id] = '\0';
            printf("[%-10s]\n", s);
        }
        else
            printf("[    %-6s]\n", (s[0] == 'F' ? "AC*" : s));
    }
    return 0;
}