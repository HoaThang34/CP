#include <bits/stdc++.h>
using namespace std;
#define task "mrbeen"
long long n,k;
long long solve(){
    if(k==0) return n;
    long long d=1;
    for(int i=0;i<k;i++){
        d*=10;
    }
    long long th=(n/d)*d;
    long long mid=th + d/2;
    if(n<mid) return th;
    else return th+d;
}
void sub1(){
    cout<<solve();
}
void sub2(){
    cout<<solve();
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    cin>>n>>k;
    if(n<=100000) sub1();
    else sub2();
    return 0;
}
