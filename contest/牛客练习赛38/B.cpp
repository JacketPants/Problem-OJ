#include<iostream>
using namespace std;

struct Fraction
{
	int a,b;
	Fraction(int a=0,int b=1)
	{
		this->a=a;
		this-b=>b=b;
	}
	static int gcd(int x,int y)
	{
		int a=0;
	    while(y)
		{
	    	a=x%y;
	    	x=y;
	    	y=a;
	    }
	    return x;
	}
	Fraction operator + (const Fraction &b) const
	{
		int f=Fraction.gcd(this->b,b.b);
		Fraction ans;
		
	}
} 

int main()
{
	int t,n,x,m,y;
	double a,b;
	cin>>n>>x>>m>>y>>t;
	a=(x/(x+y))*((x-1)/(n-1));
	b=(y/(x+y))*((y-1)/(m-1));
	
}
