#include<bits/stdc++.h>  
using namespace std;  
const int N=2e5+5;  
ll p,a[N],sum[N],s[N];  
int n;  
int lowbit(int i)  
{  
    return i&(-i);  
}  
void update(int i)  
{  
    while(i<=n)  
    {  
        sum[i]+=1;  
        i+=lowbit(i);  
    }  
}  
ll get_sum(ll i)  
{  
    ll ans=0;  
    while(i)  
    {  
        ans+=sum[i];  
        i-=lowbit(i);  
    }  
    return ans;  
}  
int main()  
{  
    while(~scanf("%d",&n))  
    {  
        memset(sum,0,sizeof(sum));  
        memset(s,0,sizeof(s));  
        ll ans=0,Ans=0;  
        for(int i=1; i<=n; i++)  
        {  
            scanf("%lld",&a[i]);  
            s[i]=a[i];  
        }  
        //离散化  
        sort(s,s+n);  
        int k=unique(s,s+n)-s;  
        for(int i=1; i<=n; i++) a[i]=(lower_bound(s,s+k,a[i])-s)+1;//保证下标从1开始  
  
        for(int i=1; i<=n; i++)  
        {  
            ll tmp=get_sum(a[i]);  
            update(a[i]);  
            ans+=tmp;//i前面小于等于a[i]的数个数  
            Ans+=i-1-tmp;//i前面小于等于a[i]的数个数，逆序数  
//        printf("i==%d a[i]==%lld tmp==%lld  ans==%lld\n",i,a[i],tmp,i-tmp);  
        }  
        printf("%lld\n",ans);//小于等于当前元素的个数总和  
        printf("%lld\n",Ans);//求逆序数  
    }  
    return 0;  
}

#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int MAXN = 500010;

int n;
int tmpNum[MAXN] , num[MAXN];
int treeNum[MAXN];

int lowbit(int x){
    return x&(-x);
}

int getSum(int x){
    int sum = 0;
    while(x){
        sum += treeNum[x];
        x -= lowbit(x);
    }
    return sum;
}

void add(int x , int val){
    while(x < MAXN){
         treeNum[x] += val;
         x += lowbit(x);
    }
}

long long solve(){
    long long ans = 0;
    memcpy(tmpNum , num , sizeof(num));
    memset(treeNum , 0 , sizeof(treeNum));
    sort(num+1 , num+1+n);
    int len = unique(num+1 , num+1+n)-(num+1);
    for(int i = 1 ; i <= n ; i++){
        int id = lower_bound(num+1 , num+1+n,tmpNum[i])-num;
        ans += i-getSum(id)-1;
        add(id , 1);
    }
    return ans;
}

int main()
{
    int x, y;
    while(scanf("%d%d%d" , &n,&x,&y)!=EOF){
         for(int i = 1 ; i <= n ; i++)
             scanf("%d" , &num[i]);
         printf("%lld\n" , solve()*min(x,y));
    }
    return 0;
}