#include <iostream>

using namespace std;

int main()
{
    int t, h, m, x, y, f;
    cin >> t;
    while (t--)
    {
        char buf[10] = "";
        scanf("%d%d%s", &h, &m, buf);
        h -= 8;
        f = buf[3] == '+' ? 1 : -1;
        buf[3] = '+';
        if (!buf[5])
        {
            buf[5] = '.';
            buf[6] = '0';
            buf[7] = '\0';
        }
        else if (!buf[6])
        {
            buf[6] = '.';
            buf[7] = '0';
            buf[8] = '\0';
        }
        sscanf(buf, "UTC+%d.%d", &x, &y);
        h += f * x;
        m += f * y * 6;
        while (m < 0)
        {
            h--;
            m += 60;
        }
        h = (h + m / 60 + 24) % 24;
        m = (m + 60) % 60;
        printf("%02d:%02d\n", h, m);
    }
    return 0;
}
/*
100
23 53 UTC+8.1
23 53 UTC+8.2
23 53 UTC+8.3
23 53 UTC+8.4
23 53 UTC+8.5
23 53 UTC+8.6
23 53 UTC+8.7
23 53 UTC+8.8
23 53 UTC+8.9
23 53 UTC+13.1
23 53 UTC+13.2
23 53 UTC+13.3
23 53 UTC+13.4
23 53 UTC+13.5
23 53 UTC+13.6
23 53 UTC+13.7
23 53 UTC+13.8
23 53 UTC+13.9
23 53 UTC-8.1
23 53 UTC-8.2
23 53 UTC-8.3
23 53 UTC-8.4
23 53 UTC-8.5
23 53 UTC-8.6
23 53 UTC-8.7
23 53 UTC-8.8
23 53 UTC-8.9
23 53 UTC-13.1
23 53 UTC-13.2
23 53 UTC-13.3
23 53 UTC-13.4
23 53 UTC-13.5
23 53 UTC-13.6
23 53 UTC-13.7
23 53 UTC-13.8
23 53 UTC-13.9
*/