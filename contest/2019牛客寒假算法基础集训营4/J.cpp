#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	double a,b,phi;
	cin>>a>>b>>phi;
	printf("%.7lf\n",sqrt(a*a+b*b+2*a*b*cos(phi/180*3.1415926)));
	return 0;
} 
