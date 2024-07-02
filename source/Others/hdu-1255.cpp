//一定要从0开始标号
#include <bits/stdc++.h>
#define INF 0x3f3f3f
#define MAXN 100010
using namespace std;
struct Node
{
	int id;
	int val;
	int mark;
};
Node t[MAXN * 4];
void Bulid(Node *tree, int *arr, int root, int start, int end)
{
	tree[root].mark = 0;
	if (start == end)
	{
		//叶子节点
		tree[root].val = arr[start];
		tree[root].id = start;
	}
	else
	{
		int m = (start + end) / 2;
		//记录区间中值，进行分叉
		Bulid(tree, arr, root * 2 + 1, start, m);
		Bulid(tree, arr, root * 2 + 2, m + 1, end);
		//以下为记录内容，模板记录最小值
		if (tree[root * 2 + 1].val < tree[root * 2 + 2].val)
		{
			tree[root].val = tree[root * 2 + 1].val;
			tree[root].id = tree[root * 2 + 1].id;
		}
		else
		{
			tree[root].val = tree[root * 2 + 2].val;
			tree[root].id = tree[root * 2 + 2].id;
		}

		// tree[root].val = min(tree[root * 2 + 1].val, tree[root * 2 + 2].val);
	}
}

void PushDown(Node *tree, int root)
{
	if (tree[root].mark)
	{
		//记录儿子节点的记录值
		tree[root * 2 + 1].mark += tree[root].mark;
		tree[root * 2 + 2].mark += tree[root].mark;
		//更新儿子节点的记录值
		//以下为记录内容的改变，模板记录最小值
		tree[root * 2 + 1].val += tree[root].mark;
		tree[root * 2 + 2].val += tree[root].mark;
		//结束，归位
		tree[root].mark = 0;
	}
}

pair<int, int> Query(Node *tree, int root, int start, int end, int qStart, int qEnd)
{
	//当前查询区间是，目标区间的一部分，直接返回当前值
	if (start >= qStart && end <= qEnd)
		return pair<int, int>(tree[root].val, tree[root].id);
	//当前查询区间在，目标区间之外
	else if (qStart > end || qEnd < start)
		return pair<int, int>(INF, INF);
	//当前查询区间有，一部分在目标区间内，继续分割查找
	PushDown(tree, root);
	//对标记进行整理
	int m = (start + end) / 2;
	//以下是模板内容
	return min(Query(tree, root * 2 + 1, start, m, qStart, qEnd),
			   Query(tree, root * 2 + 2, m + 1, end, qStart, qEnd));
}

void Updata(Node *tree, int root, int start, int end, int uStart, int uEnd, int n)
{
	if (start > uEnd || end < uStart)
		//当前更新区间在，目标区间之外，不做任何操作
		return;
	if (uStart <= start && end <= uEnd)
	//当前更新区间是，目标区间的一部分，更新值
	{
		tree[root].mark += n;
		tree[root].val += n;
		return;
	}
	PushDown(tree, root);
	int m = (start + end) / 2;
	//获取中间位置，并分段查找
	Updata(tree, root * 2 + 1, start, m, uStart, uEnd, n);
	Updata(tree, root * 2 + 2, m + 1, end, uStart, uEnd, n);
	//以下是改变内容，模板记录最小值
	if (tree[root * 2 + 1].val < tree[root * 2 + 2].val)
	{
		tree[root].val = tree[root * 2 + 1].val;
		tree[root].id = tree[root * 2 + 1].id;
	}
	else
	{
		tree[root].val = tree[root * 2 + 2].val;
		tree[root].id = tree[root * 2 + 2].id;
	}
}
int mylist[MAXN];
int main()
{
	int n, q, l, r;
	char op[10];
	pair<int, int> ans;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		printf("%d ", i);
	putchar('\n');
	for (int i = 0; i < n; i++)
		cin >> mylist[i];
	Bulid(t, mylist, 0, 0, n - 1);
	for (int i = 0; i < q; i++)
	{
		cin >> op >> l >> r;
		if (op[0] == 'q')
		{
			ans = Query(t, 0, 0, n - 1, l - 1, r - 1);
			printf("mylist[%d]:%d\n", ans.second, ans.first);
		}
		else
		{
			Updata(t, 0, 0, n - 1, l - 1, r - 1, 1);
		}
	}
	return 0;
}
