#include <bits/stdc++.h>
using namespace std;
int p;
bool grid[3010][3010];
int main()
{
	p = 47;
	for (int i = 0; i < p; i++)
		for (int j = 0; j < p; j++)
			for (int k = 0; k < p; k++)
				grid[i * p + j][k * p + (j * k + i) % p] = 1;
	puts("2000");
	for (int i = 0; i < 2000; i++)
	{
		for (int j = 0; j < 2000; j++)
			printf("%d", grid[i][j]);
		putchar('\n');
	}
}
