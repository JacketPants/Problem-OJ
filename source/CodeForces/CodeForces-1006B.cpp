#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int list[2000], ans[2000], is[2000];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	int n, k, tem, a = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", list + i);
		ans[i] = list[i];
	}
	sort(ans, ans + n, cmp);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			if (ans[i] == list[j] && !is[j])
			{
				a += ans[i];
				is[j] = true;
				break;
			}
	cout << a << endl;
	tem = 0;
	bool flag = false;
	int i = 0;
	for (int j = 1; i < n && j < k; i++)
	{
		tem++;
		if (is[i])
		{
			if (flag)
				putchar(' ');
			printf("%d", tem);
			flag = true;
			tem = 0;
			j++;
		}
	}
	if (k > 1)
		putchar(' ');
	printf("%d\n", n - i);
	return 0;
}
