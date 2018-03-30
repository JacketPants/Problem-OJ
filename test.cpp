#include<iostream>
#include<string>
#include<cstring>
#include<map>
#include<cstdio>
using namespace std;
struct kv
{
    int k;
    int v;
    kv(int a,int b){
        k=a;v=b;
    }
};
bool operator < (const kv& a,const kv& b){
    if(a.k<b.k)return 1;
    if(a.k>b.k)return 0;

    return a.v<b.v;
}
int main()
{
    //ios::sync_with_stdio(false);

    int m,n;
    while(cin>>n>>m){
        getchar();
        char line[100];
        string s[10020][11];
        int a[n][m];
        map<string,int> con;
        int num=1;

        for(int i=0;i<n;i++){
            gets(line);
            int c=0;
            int len=strlen(line);
            for(int j=0;j<len;j++){
                if(line[j]==','){
                    c++;
                    if(!con.count(s[i][c-1])){
                        con[s[i][c-1]]=num++;
                        a[i][c-1]=num-1;
                    }
                    else a[i][c-1]=con[s[i][c-1]];
                }
                else s[i][c].push_back(line[j]);
            }
            if(!con.count(s[i][c])){
                con[s[i][c]]=num++;
                a[i][c]=num-1;
            }
            else a[i][c]=con[s[i][c]];
        }

        int sign=0;
        for(int c1=0;c1<m;c1++){
            for(int c2=c1+1;c2<m;c2++){
                map<kv,int> database;
                for(int i=0;i<n;i++){
                    kv k(a[i][c1],a[i][c2]);
                    if(database.count(k)){
                        sign=1;
                        cout<<"NO"<<endl;
                        cout<<database[k]<<" "<<i+1<<endl;
                        cout<<c1+1<<" "<<c2+1<<endl;
                        goto ssss;
                    }
                    else {
                        database[k]=i+1;
                    }
                }
            }
        }
        ssss:;
        if(sign==0)cout<<"YES"<<endl;
    }
    return 0;
}