#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
int t[1000000];
void Bulid(int *tree, int *arr, int root, int start, int end)
{
	if (start == end)
	{
		tree[root] = arr[start];
	}
	else
	{
		int m = (start + end) / 2;
		Bulid(tree, arr, root * 2 + 1, start, m);
		Bulid(tree, arr, root * 2 + 2, m + 1, end);
		tree[root] = max(tree[root * 2 + 1], tree[root * 2 + 2]);
	}
}

int Query(int *tree, int root, int start, int end, int qStart, int qEnd)
{
	if (start >= qStart && end <= qEnd)
		return tree[root];
	else if (qStart > end || qEnd < start)
		return -INF;
	int m = (start + end) / 2;
	return max(Query(tree, root * 2 + 1, start, m, qStart, qEnd),
			   Query(tree, root * 2 + 2, m + 1, end, qStart, qEnd));
}

void Updata(int *tree, int root, int start, int end, int x, int n)
{
	if (start == end)
	{
		tree[root] = n;
	}
	else
	{
		int m = (start + end) / 2;
		if (x <= m)
		{
			Updata(tree, root * 2 + 1, start, m, x, n);
		}
		else
		{
			Updata(tree, root * 2 + 2, m + 1, end, x, n);
		}
		tree[root] = max(tree[root * 2 + 1], tree[root * 2 + 2]);
	}
}
int mylist[200001];
int main()
{
	int n, q, l, r;
	char op[10];
	while (~scanf("%d%d", &n, &q))
	{
		for (int i = 0; i < n; i++)
			scanf("%d", mylist + i);
		Bulid(t, mylist, 0, 0, n - 1);
		for (int i = 0; i < q; i++)
		{
			scanf("%s%d%d", op, &l, &r);
			if (op[0] == 'Q')
			{
				printf("%d\n", Query(t, 0, 0, n - 1, l - 1, r - 1));
			}
			else
			{
				Updata(t, 0, 0, n - 1, l - 1, r);
			}
		}
	}
	return 0;
}
// #include <cstring>
// #include <iostream>
// using namespace std;

// const int MAXN = 3e5;
// int a[MAXN], h[MAXN];
// int n, m;

// int lowbit(int x)
// {
// 	return x & (-x);
// }
// void updata(int x)
// {
// 	int lx, i;
// 	while (x <= n)
// 	{
// 		h[x] = a[x];
// 		lx = lowbit(x);
// 		for (i = 1; i < lx; i <<= 1)
// 			h[x] = max(h[x], h[x - i]);
// 		x += lowbit(x);
// 	}
// }
// int query(int x, int y)
// {
// 	int ans = 0;
// 	while (y >= x)
// 	{
// 		ans = max(a[y], ans);
// 		y--;
// 		for (; y - lowbit(y) >= x; y -= lowbit(y))
// 			ans = max(h[y], ans);
// 	}
// 	return ans;
// }
// int main()
// {
// 	int i, j, x, y, ans;
// 	char c;
// 	while (~scanf("%d%d", &n, &m))
// 	{
// 		memset(h, 0, sizeof h);
// 		for (i = 1; i <= n; i++)
// 		{
// 			scanf("%d", a + i);
// 			updata(i);
// 		}
// 		for (i = 1; i <= m; i++)
// 		{
// 			getchar();
// 			c = getchar();
// 			scanf("%d%d", &x, &y);
// 			if (c == 'Q')
// 			{
// 				printf("%d\n", query(x, y));
// 			}
// 			else if (c == 'U')
// 			{
// 				a[x] = y;
// 				updata(x);
// 			}
// 		}
// 	}
// 	return 0;
// }