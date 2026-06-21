/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

void hoathang(){
    int n,m;cin>>n>>m;
    vector<long long> v(n+1);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<long long> df(n+3,0);
    for(int i=0;i<m;i++){
        int l,r;cin>>l>>r;
        if(l<r){ df[l]++; df[r]--; }
    }
    vector<int> cv(n+2,0);
    long long cur=0;
    for(int i=1;i<=n-1;i++){
        cur+=df[i];
        cv[i]= (cur>0 ? 1 : 0);
    }
    vector<long long> bs;
    for(int i=1;i<=n;){
        int j=i;
        while(j<n && cv[j]) ++j;
        bs.push_back(j-i+1);
        i=j+1;
    }
    vector<char> ok(n+1,0);
    ok[0]=1;
    for(long long len:bs){
        for(int s=n-(int)len;s>=0;--s) if(ok[s]) ok[s+len]=1;
    }
    vector<int> pr(n+1,0);
    pr[0]= ok[0];
    for(int s=1;s<=n;s++) pr[s]=pr[s-1]+(ok[s]?1:0);
    vector<long long> fr(n+1,0);
    for(int i=0;i<n;i++) if(1<=v[i] && v[i]<=n) fr[(int)v[i]]++;
    vector<long long> pf(n+1,0);
    for(int x=1;x<=n;x++) pf[x]=pf[x-1]+fr[x];
    string res; res.reserve(n);
    for(int x=1;x<=n;x++){
        int cL = (int)pf[x-1];
        int cE = (int)fr[x];
        int L = cL;
        int R = min(n, cL + cE);
        bool okx=false;
        if(L<=R){
            int got = pr[R] - (L?pr[L-1]:0);
            okx = (got>0);
        }
        res.push_back(okx ? '1' : '0');
    }
    cout<<res<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(nap".inp","r")){
        freopen(nap".inp","r",stdin);
        freopen(nap".out","w",stdout);
    }
    int t; if(!(cin>>t)) return 0;
    while(t--) hoathang();
    return 0;
}
