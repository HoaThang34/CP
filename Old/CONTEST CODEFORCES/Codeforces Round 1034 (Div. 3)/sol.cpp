/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""

void hoathang(){
    int n,k;
    cin>>n>>k;
    vector<long long> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int need=(k+1)/2;
    multiset<long long> lo,hi;
    auto rebalance=[&](){
        while((int)lo.size()>need){
            auto it=prev(lo.end());
            hi.insert(*it);
            lo.erase(it);
        }
        while((int)lo.size()<need){
            auto it=hi.begin();
            lo.insert(*it);
            hi.erase(it);
        }
    };
    for(int i=0;i<k;i++){
        if(lo.empty()||a[i]<=*prev(lo.end()))lo.insert(a[i]);
        else hi.insert(a[i]);
    }
    rebalance();
    cout<<*prev(lo.end());
    for(int i=k;i<n;i++){
        long long out=a[i-k];
        auto itLo=lo.find(out);
        if(itLo!=lo.end())lo.erase(itLo);
        else{
            auto itHi=hi.find(out);
            hi.erase(itHi);
        }
        long long in=a[i];
        if(in<=*prev(lo.end()))lo.insert(in);
        else hi.insert(in);
        rebalance();
        cout<<' '<<*prev(lo.end());
    }
    cout<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t=1;
    // cin>>t;
    while(t--){
        hoathang();
    }
    return 0;
}
