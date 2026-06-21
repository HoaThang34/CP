/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

void hoathang(){
    int n,m;cin>>n>>m;
    vector<pair<long long,long long>> a(m);
    long long L=1,R=n;
    for(int i=0;i<m;i++){
        cin>>a[i].first>>a[i].second;
        L=max(L,a[i].first);
        R=min(R,a[i].second);
    }
    vector<long long> p(n+1,-1),used(n,0);
    if(L<=R){
        long long pos=L;
        p[pos]=0;
        used[0]=1;
    }else{
        const long long INF=1e9;
        vector<long long> Ls(n+1,-INF),Rs(n+1,INF),cover(n+1,0);
        for(int i=0;i<m;i++){
            long long l=a[i].first,r=a[i].second;
            for(long long x=l;x<=r;x++){
                cover[x]++;
                Ls[x]=max(Ls[x],l);
                Rs[x]=min(Rs[x],r);
            }
        }
        long long pos0=-1,pos1=-1,pos2=-1;
        long long freePos=-1;
        for(long long x=1;x<=n;x++)if(!cover[x]){
            freePos=x;
            break;
        }
        if(freePos!=-1){
            pos0=freePos;
            p[pos0]=0;
            used[0]=1;
        }else{
            long long xchoose=-1;
            for(long long x=1;x<=n;x++){
                if(cover[x]&&Rs[x]-Ls[x]+1>=2){
                    xchoose=x;
                    break;
                }
            }
            if(xchoose!=-1){
                pos0=xchoose;
                if(Ls[xchoose]<xchoose)pos1=Ls[xchoose];
                else pos1=Rs[xchoose];
                p[pos0]=0;
                used[0]=1;
                p[pos1]=1;
                used[1]=1;
            }else{
                pos0=1;
                pos1=n;
                pos2=2;
                p[pos0]=0;
                used[0]=1;
                p[pos1]=1;
                used[1]=1;
                p[pos2]=2;
                used[2]=1;
            }
        }
    }
    vector<long long> rest;
    for(long long v=0;v<n;v++)if(!used[v])rest.push_back(v);
    long long j=0;
    for(long long i=1;i<=n;i++)if(p[i]==-1)p[i]=rest[j++];
    for(long long i=1;i<=n;i++){
        if(i>1)cout<<' ';
        cout<<p[i];
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(nap".inp","r")){
        freopen(nap".inp","r",stdin);
        freopen(nap".out","w",stdout);
    }
    int t;
    if(!(cin>>t))return 0;
    while(t--){
        hoathang();
    }
    return 0;
}
    