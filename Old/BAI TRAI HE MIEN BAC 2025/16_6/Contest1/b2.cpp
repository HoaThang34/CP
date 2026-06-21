#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"

ll dem(ll n){
    if(n==0) return 0;
    ll res=n;
    res-=n/2;
    res-=n/3;
    res-=n/5;
    res-=n/7;

    res+=n/6;
    res+=n/10;
    res+=n/14;
    res+=n/15;
    res+=n/21;
    res+=n/35;

    res-=n/30;
    res-=n/42;
    res-=n/70;
    res-=n/105;

    res+=n/210;

    return res;
}

ll find(ll k){
    ll l=1, r=5e18, ans=r;
    while(l<=r){
        ll m=(l+r)/2;
        if(dem(m)>=k){
            ans=m;
            r=m-1;
        } else l=m+1;
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }

    int t; cin>>t;
    while(t--){
        ll v, k; cin>>v>>k;
        cout<<dem(v)<<" "<<find(k)<<"\n";
    }

    return 0;
}
