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
 
 
#define o(...) if(local=='L') {__f(#__VA_ARGS__, __VA_ARGS__); cout<<endl;}
 
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
 
 
////////////////#####################OUPUT###############///////////////////////
 
template <typename T>
void out(T& n)
{
    cout << n;
}
 
template <typename T, typename T1>
void out(pair<T, T1> &p)
{
    cout << "(";
    out(p.ff);
    cout << ",";
    out(p.ss);
    cout << ")";
}
 
template <typename T>
void out(T arr[], ll n)
{
    for (ll i = 0; i < n; i++)
    {
        out(arr[i]);
        cout << " ";
    }
}
 
template <typename T>
void out(vector<T> &arr)
{
 
    cout << "[ ";
    for (ll i = 0; i < arr.size(); i++)
    {
        out(arr[i]);
        if (i!=arr.size()-1)
            cout << ", ";
    }
    cout << " ]";
 
}
 
 
 
template <typename T>
void out(set<T> &arr)
{
    for (auto i:arr)
    {
        out(i);
        cout << " ";
    }
}

template <typename T>
void out(multiset<T> &arr)
{
    for (auto i:arr)
    {
        out(i);
        cout << " ";
    }
}
 
template <typename T, typename T1>
void out(map<T,T1> &m)
{
    for (auto i:m)
    {
        out(i.first);
        cout<<" -> ";
        out(i.second);
        cout<<", ";
    }
}
 
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cout << name << " : ";
    out(arg1);
}
 
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char *comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : ";
    out(arg1);
    cout << " | ";
    __f(comma + 1, args...);
}
 
 
////////////////////////////////////END TEMPLATE//////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void cal() {
}


void solve() {
    int n,a[200005],b[200005];
    ll suma=0,sumb=0,cntn=0,cnt=0;
    // int cnt[3][3]; // (-1,-1) (-1,0) (-1,1) (0,-1) (0,0) (0,1) (1,-1) (1,0) (1,1)
    // memset(cnt,0,sizeof(cnt));
    read(n);
    read(a,n);
    read(b,n);
    // for (int i=0;i<n;i++) {
    //     cnt[a[i]+1][b[i]+1]++;
    // }
    for (int i=0;i<n;i++) {
        if(a[i]==-1&&b[i]==-1) {
            cntn++;
        } else if (a[i]==1 && b[i]==1) {
            cnt++;
        } else {
            if (a[i]>b[i]) {
                suma+=a[i];
            } else {
                sumb+=b[i];
            }
        }
    }
    if (suma < sumb) {
        swap(suma,sumb);
    }
    ll disCnt=cnt-cntn,disSum=suma-sumb,ans;

    if (disSum>=(cnt+cntn)) {
        ans = sumb+cnt;
    } else {
        if (disSum<cnt) {
            sumb=suma;
            cnt-=disSum;
            if(cnt>=cntn) {
                ans=sumb+(cnt-cntn)/2;
            } else {
                ans=sumb-(cntn-cnt)/2-(cntn-cnt)%2;
            }
        } else {
            sumb+=cnt;
            cntn-=(suma-sumb);
            suma=sumb;
            ans=sumb-cntn/2-cntn%2;
        }
    } 

    // if (abs(disSum) >= abs(disCnt)) {
    //     if (disCnt>=0) {
    //         ans=min(suma,sumb)+disCnt;
    //     } else {
    //         ans=max(suma,sumb)+disCnt;
    //     }
    // } else {
    //     if (disCnt>0) {
    //         ans=max(suma,sumb)+(disCnt-disSum)/2;
    //     } else {
    //         ans=min(suma,sumb)-(disCnt-disSum)/2-(disCnt-disSum)%2;
    //     }
    // }
    
    out(ans);
    out("\n");
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
 
 
    cin>>t1;
 
    cal();
 
    while (t1--) {
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