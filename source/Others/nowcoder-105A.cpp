#include<iostream>
using namespace std;
int main()
{
    int t;
    int a,b,c,d,e,f,g,h;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%dday%d:%d:%d",&e,&f,&g,&h);
        scanf("%dday%d:%d:%d",&a,&b,&c,&d);
        a-=e;
        b-=f;
        c-=g;
        d-=h;
        printf("%d\n",a*24*60*60+b*60*60+c*60+d);
    }
    return 0;
}
/*
2
1day03:26:12
1day04:26:12
123day15:00:01
19999day15:00:00
*/