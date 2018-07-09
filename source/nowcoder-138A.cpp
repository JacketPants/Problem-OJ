#include <iostream>

using namespace std;

int main()
{
	int n, m, tem, is, c;
	double a, b;
	cin >> n >> m;
	a = b = c = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &tem, &is);
		b += tem;
		a += is ? tem * 0.8 : tem;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &is, &tem);
		if (b >= is)
			c = tem > c ? tem : c;
	}
	b -= c;
	printf("%0.2lf\n", a > b ? b : a);
	return 0;
}
