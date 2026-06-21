/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define long long long

#define nap "POST"

const int N=3e5+5;
const int INF=1e9;

int n,q,a[N],mn[N],mx[N];
long res[N];
vector<pair<int,int>> Q[N];
struct Node{int m,c,lz,hz; long s;} t[4*N];

void bld(int i, int l, int r){
    t[i]={INF, r-l+1, 0, 0, 0};
    if(l==r) return;
    int m=(l+r)/2;
    bld(i*2,l,m); bld(i*2+1,m+1,r);
}

void push(int i){
    if(t[i].lz){
        t[i*2].m+=t[i].lz; t[i*2].lz+=t[i].lz;
        t[i*2+1].m+=t[i].lz; t[i*2+1].lz+=t[i].lz;
        t[i].lz=0;
    }
    if(t[i].hz){
        if(t[i*2].m==t[i].m){
            t[i*2].s+=1LL*t[i*2].c*t[i].hz;
            t[i*2].hz+=t[i].hz;
        }
        if(t[i*2+1].m==t[i].m){
            t[i*2+1].s+=1LL*t[i*2+1].c*t[i].hz;
            t[i*2+1].hz+=t[i].hz;
        }
        t[i].hz=0;
    }
}

void pull(int i){
    t[i].m=min(t[i*2].m, t[i*2+1].m);
    t[i].c=0;
    if(t[i].m==t[i*2].m) t[i].c+=t[i*2].c;
    if(t[i].m==t[i*2+1].m) t[i].c+=t[i*2+1].c;
    t[i].s=t[i*2].s+t[i*2+1].s;
}

void upd(int i, int l, int r, int u, int v, int val){
    if(l>v || r<u) return;
    if(l>=u && r<=v){
        t[i].m+=val; t[i].lz+=val;
        return;
    }
    push(i);
    int m=(l+r)/2;
    upd(i*2,l,m,u,v,val); upd(i*2+1,m+1,r,u,v,val);
    pull(i);
}

void set0(int i, int l, int r, int p, int val){
    if(l==r){
        t[i].m=val; t[i].c=1; t[i].s=0;
        return;
    }
    push(i);
    int m=(l+r)/2;
    if(p<=m) set0(i*2,l,m,p,val);
    else set0(i*2+1,m+1,r,p,val);
    pull(i);
}

void his(int i, int l, int r, int u, int v){
    if(l>v || r<u) return;
    if(l>=u && r<=v){
        if(t[i].m==0){
            t[i].s+=t[i].c; t[i].hz++;
        }
        return;
    }
    push(i);
    int m=(l+r)/2;
    his(i*2,l,m,u,v); his(i*2+1,m+1,r,u,v);
    pull(i);
}

long get(int i, int l, int r, int u, int v){
    if(l>v || r<u) return 0;
    if(l>=u && r<=v) return t[i].s;
    push(i);
    int m=(l+r)/2;
    return get(i*2,l,m,u,v)+get(i*2+1,m+1,r,u,v);
}

void hoathang(){
    cin>>n>>q;
    map<int,int> pos;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(!pos.count(a[i])) pos[a[i]]=i;
        mn[i]=pos[a[i]];
    }
    pos.clear();
    for(int i=n;i>=1;i--){
        if(!pos.count(a[i])) pos[a[i]]=i;
        mx[i]=pos[a[i]];
    }
    for(int i=1;i<=q;i++){
        int u,v; cin>>u>>v;
        Q[v].push_back({u,i});
    }

    bld(1,1,n);
    vector<int> s1={0}, s2={0};

    for(int i=1;i<=n;i++){
        upd(1,1,n,1,i-1,-1);

        while(s1.size()>1 && mx[s1.back()]<mx[i]){
            int p=s1.back(); s1.pop_back();
            upd(1,1,n,s1.back()+1,p,mx[i]-mx[p]);
        }
        s1.push_back(i);

        while(s2.size()>1 && mn[s2.back()]>mn[i]){
            int p=s2.back(); s2.pop_back();
            upd(1,1,n,s2.back()+1,p,mn[p]-mn[i]);
        }
        s2.push_back(i);

        set0(1,1,n,i,mx[i]-mn[i]);
        if(t[1].m==0) his(1,1,n,1,i);

        for(auto x:Q[i]) res[x.second]=get(1,1,n,x.first,i);
    }
    for(int i=1;i<=q;i++) cout<<res[i]<<endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
