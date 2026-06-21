/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n;
vector <long long> a;
map<long long,int> f;

void hoathang(){
    cin>>n;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[a[i]]++;
    }
    if(f.size()==1){
        cout<<1;
        return;
    }
    long long val=a[1], mx=0;
    for(auto &x:f){
        if(x.second>mx){
            mx=x.second;
            val=x.first;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=val){
            map<long long,int> g=f;
            g[a[i]]--;
            if(g[a[i]]==0) g.erase(a[i]);
            if(g.size()==1) {
                cout<<i;
                return;
            }
        }
    }
    cout<<0;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}