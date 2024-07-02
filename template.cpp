#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
#define maxn 100000000000017
#define endl "\n"
#define mk make_pair
#define pll pair<ll, ll>
#define vll vector<ll>
#define vld vector<ld>
#define vpll vector<ppl>
#define ff first
#define ss second
#define pb push_back

typedef long long ll;
typedef long double ld;

#define o(...)                          \
    if (local == 'L')                   \
    {                                   \
        __f(#__VA_ARGS__, __VA_ARGS__); \
        cout << endl;                   \
    }

#define Ns 1000007

char local = 'O';

////////////////#####################INPUT###############///////////////////////

template <typename T>
void read(T &p)
{
    cin >> p;
}

template <typename T, typename T1>
void read(pair<T, T1> &p)
{
    read(p.ff);
    read(p.ss);
}

template <typename T>
void read(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        read(arr[i]);
    }
}

template <typename T>
void read(vector<T> &arr)
{
    for (ll i = 0; i < arr.size(); i++)
    {
        read(arr[i]);
    }
}

/// Print///
template <typename T>
void print(T &x, char *end = "\n")
{
    cout << n;
    cout << end;
}

template <typename T, typename T1>
void print(pair<T, T1> &x, char *end = "\n")
{
    cout << "(";
    print(x.ff, "");
    cout << ",";
    print(x.ss, "");
    cout << ")";
    cout << end;
}

template <typename T>
void print(T arr[], ll n, char *split = " ", char *end = "\n")
{
    for (ll i = 0; i < n; i++)
    {
        print(arr[i], split);
    }
    cout << end;
}

template <typename T>
void print(vector<T> &arr, char split = ' ', char end = '\n')
{

    for (auto i : arr)
    {
        print(i, split);
    }
    cout << end;
}

template <typename T>
void print(set<T> &arr, char split = ' ', char end = '\n')
{
    for (auto i : arr)
    {
        print(i, split);
    }
    cout << end;
}

template <typename T>
void print(multiset<T> &arr, char split = ' ', char end = '\n')
{
    for (auto i : arr)
    {
        print(i, split);
    }
    cout << end;
}

////////////////////////////////////END TEMPLATE//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void cal()
{
}

void solve()
{
}

int main()
{

#ifdef L
    local = 'L';
    time_t start, end;
    time(&start);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t1;

    t1 = 1;

    cin >> t1;

    cal();

    while (t1--)
    {
        solve();
    }

#ifdef L
    time(&end);
    double time_taken = double(end - start);
    cout << endl
         << endl
         << endl
         << "Time taken by program is : " << fixed
         << time_taken << setprecision(6);
    cout << " sec " << endl;
#endif
}