#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#define tangtoc cin.tie(0)->ios_base::sync_with_stdio(0)
using namespace std;

long long a[100001],t[400001];
int n;
void build(int id,int l,int r){
     if(l==r){
        t[id]=a[l];
        return;
     }
     int mid=(l+r)/2;
     build(2*id, l,mid);
     build(2*id+1, mid+1,r);
     t[id]=min(t[id*2],t[id*2+1]);
}

void update(int id,int l,int r,int pos,int val){
     if(l==r){
        t[id]=val;
        return;
     }
     int mid=(l+r)/2;
     if(pos <= mid)
        update(id * 2,l,mid,pos,val);
     else update(id*2+1,mid +1 , r ,pos,val);
     t[id]= min(t[id*2] , t[id *2 +1]);
}

long long get(int id,int l,int r,int u,int v){
     if(u > r || v < l)
        return LLONG_MAX;
     if( u<=l && r <=v)
        return t[id];
     int mid=(l+r)/2;
     long long t1= get(id*2,l,mid,u,v),
               t2= get(id*2+1,mid+1,r,u,v);
     return min(t1,t2);
}
int main()
{
    tangtoc;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    build(1,0,n-1);
    int q;
    cin>>q;
    while(q--){
        short mode;
        cin>>mode;
        if(mode == 1){
            int i,v;
            cin>>i>>v;
            update(1,0,n-1,i,v);
        }
        else{
            int l,r;
            cin>>l>>r;
            cout<<get(1,0,n-1,l,r)<<"\n";
        }
    }
    return 0;
}
