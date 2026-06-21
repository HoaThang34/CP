#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
const long long MOD=1e9+7;
long long xuli(long long x){
    vector<long long> f(x+1,0);
    f[0]=1;
    for(int i=1;i<=x;i++){
        if(i%2)f[i]=f[i-1];
        else f[i]=(f[i-1]+f[i/2])%MOD;
    }
    return f[x];
}
void subtask1(){
    for(int i=1;i<=n;i++){
        cout<<xuli(a[i])<<'\n';
    }
}
void subtask2(){
    long long mx=*max_element(a.begin()+1,a.end());
    vector<long long> coin;
    for(long long i=1;i<=mx;i<<=1)coin.push_back(i);
    vector<long long> f(mx+1,0);
    f[0]=1;
    for(long long c:coin){
        for(long long i=c;i<=mx;i++){
            f[i]=(f[i]+f[i-c])%MOD;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<f[a[i]]<<'\n';
    }
}
#define task "tt"
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n<=20)subtask1();
    else subtask2();
    return 0;
}
