#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int n;
    cin>>n;
    int N=1<<n;
    vell a(N), g(N);
    for(int i=0;i<N;i++) cin>>a[i];
    for(int m=0;m<N;m++) g[m]=a[m];
    for(int j=0;j<n;j++){
        for(int m=0;m<N;m++){
            if((m>>j)&1) g[m]=max(g[m], g[m^(1<<j)]);
        }
    }
    for(int i=0;i<N;i++){
        cout<<g[i]<<(i==N-1?"":" ");
    }
    cout<<"\n";
    return 0;
}
