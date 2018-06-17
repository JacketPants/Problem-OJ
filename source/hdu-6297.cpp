#include <stdio.h>
int main()
{
    int t, id, prob, c, i;
    char team[20], q[20];
    scanf("%d", &t);
    while (t--)
    {
        char s[20] = "[          ]";
        scanf("%d%s%d%s", &id, team, &prob, q);
        if (q[1] == 'u')
        {
            scanf("%d", &c);
            for (i = 1; i <= c; i++)
                s[i] = 'X';
        }
        else if (q[1] == 'B')
        {
            s[5] = 'A';
            s[6] = 'C';
            s[7] = '*';
        }
        else
        {
            for (i = 0; q[i]; i++)
                s[i + 5] = q[i];
        }
        printf("%3d|%-16s|%4d|%s\n", id, team, prob, s);
    }
    return 0;
}