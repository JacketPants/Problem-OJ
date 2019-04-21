#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    while(~scanf("%lld",&n)) 
    {
    	if(n<100)
    	{
		    long long f1=1,f2=1,f3;
		    for(int i=3;i<=n;i++) {
		        f3=f1+f2;
		        f1=f2;
		        f2=f3;
		    }
		    printf("%lld\n",f3*f3-f1*f1-f1*f3);    		
		}
		else
		{
			if(n%2)
				puts("1");
			else 
				puts("-1");
		}
	}
    return 0;
}
