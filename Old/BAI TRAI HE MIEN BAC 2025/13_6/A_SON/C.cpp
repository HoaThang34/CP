#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
int n,q;
vector<int> a,st;
int xgl,cn;
void build(int id,int L,int R){
    if(L==R){
        st[id]=a[L];
        return;
    }
    int M=(L+R)>>1;
    build(id<<1,L,M);
    build(id<<1|1,M+1,R);
    st[id]=gcd(st[id<<1],st[id<<1|1]);
}
void qry(int id,int L,int R,int l,int r){
    if(cn>1||R<l||L>r) return;
    if(l<=L&&R<=r){
        if(st[id]%xgl==0) return;
        if(L==R){
            cn++;
            return;
        }
    }
    int M=(L+R)>>1;
    qry(id<<1,L,M,l,r);
    qry(id<<1|1,M+1,R,l,r);
}
void upd(int id,int L,int R,int p,int v){
    if(L==R){
        st[id]=v;
        return;
    }
    int M=(L+R)>>1;
    if(p<=M) upd(id<<1,L,M,p,v);
    else upd(id<<1|1,M+1,R,p,v);
    st[id]=gcd(st[id<<1],st[id<<1|1]);
}
void sub1(){
    st.assign(4*(n+1),0);
    build(1,1,n);
    cin>>q;
    while(q--){
        int tp; cin>>tp;
        if(tp==1){
            int l,r,x; cin>>l>>r>>x;
            xgl=x; cn=0;
            qry(1,1,n,l,r);
            cout<<(cn<=1?"YES\n":"NO\n");
        } else{
            int p,v; cin>>p>>v;
            upd(1,1,n,p,v);
        }
    }
    
}
#define task "sol"
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sub1();
    return 0;
}