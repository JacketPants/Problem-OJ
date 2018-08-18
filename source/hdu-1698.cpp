#include <bits/stdc++.h>
#define INF 0x3f3f3f
#define MAXN 100010
using namespace std;
struct Node
{
	int val;
	int mark;
};
Node t[MAXN * 4];
void Bulid(Node *tree, int root, int start, int end)
{
	tree[root].mark = 0;
	if (start == end)
	{
		tree[root].val = 1;
	}
	else
	{
		int m = (start + end) / 2;
		Bulid(tree, root * 2 + 1, start, m);
		Bulid(tree, root * 2 + 2, m + 1, end);
		tree[root].val = end - start + 1;
	}
}

void PushDown(Node *tree, int root, int l, int r)
{
	if (tree[root].mark)
	{
		tree[root * 2 + 1].mark = tree[root].mark;
		tree[root * 2 + 2].mark = tree[root].mark;
		int m = (l + r) / 2;
		tree[root * 2 + 1].val = tree[root].mark * (m - l + 1);
		tree[root * 2 + 2].val = tree[root].mark * (r - m);
		tree[root].mark = 0;
	}
}

int Query(Node *tree, int root, int start, int end, int qStart, int qEnd)
{
	if (start >= qStart && end <= qEnd)
		return tree[root].val;
	else if (qStart > end || qEnd < start)
		return 0;
	PushDown(tree, root, start, end);
	int m = (start + end) / 2;
	return Query(tree, root * 2 + 1, start, m, qStart, qEnd) +
		   Query(tree, root * 2 + 2, m + 1, end, qStart, qEnd);
}

void Updata(Node *tree, int root, int start, int end, int uStart, int uEnd, int n)
{
	if (start > uEnd || end < uStart)
		return;
	if (uStart <= start && end <= uEnd)
	{
		tree[root].mark = n;
		tree[root].val = n * (end - start + 1);
		return;
	}
	PushDown(tree, root, start, end);
	int m = (start + end) / 2;
	Updata(tree, root * 2 + 1, start, m, uStart, uEnd, n);
	Updata(tree, root * 2 + 2, m + 1, end, uStart, uEnd, n);
	tree[root].val = tree[root * 2 + 1].val + tree[root * 2 + 2].val;
}

int main()
{
	int T, n, m, a, b, c;
	cin >> T;
	for (int j = 1; j <= T; j++)
	{
		scanf("%d%d", &n, &m);
		Bulid(t, 0, 0, n - 1);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			Updata(t, 0, 0, n - 1, a - 1, b - 1, c);
		}
		printf("Case %d: The total value of the hook is %d.\n", j, Query(t, 0, 0, n - 1, 0, n - 1));
	}
}