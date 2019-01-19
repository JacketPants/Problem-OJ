#include <iostream>
#include <map>
#define MOD 998244353
using namespace std;
int a[200005];
map<int, int> l;
int main()
{
	int n, ans = 1, now;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < n; i++)
		l[a[i]] = i;
	now = l[a[0]];
	for (int i = 1; i < n; i++)
	{
		ans = i > now ? (2 * ans) % MOD : ans;
		now = l[a[i]] > now ? l[a[i]] : now;
	}
	cout << ans << endl;
	return 0;
}
