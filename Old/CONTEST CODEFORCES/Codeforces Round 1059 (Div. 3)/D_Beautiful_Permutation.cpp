/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long hoiP(int l,int r){
    cout<<"1 "<<l<<" "<<r<<endl;
    cout.flush();
    long long x;
    if(!(cin>>x))exit(0);
    return x;
}

long long hoiA(int l,int r){
    cout<<"2 "<<l<<" "<<r<<endl;
    cout.flush();
    long long x;
    if(!(cin>>x))exit(0);
    return x;
}

void hoathang(){
    int n;cin>>n;
    long long a=hoiA(1,n);
    long long p=1ll*n*(n+1)/2;
    long long k=a-p;
    int l=1,h=n,ans=n+1;
    while(l<=h){
        int m=(l+h)/2;
        long long aa=hoiA(1,m);
        long long pp=hoiP(1,m);
        long long d=aa-pp;
        if(d>0){
            ans=m;
            h=m-1;
        }else l=m+1;
    }
    int L=(ans<=n?ans:n);
    int R=L+(int)k-1;
    cout<<"! "<<L<<" "<<R<<endl;
    cout.flush();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(nap".inp","r")){
        freopen(nap".inp","r",stdin);
        freopen(nap".out","w",stdout);
    }
    int t;cin>>t;
    while(t--){
        hoathang();
    }
    return 0;
}
