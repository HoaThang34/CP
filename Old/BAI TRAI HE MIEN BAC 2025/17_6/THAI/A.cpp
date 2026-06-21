#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1),b(m+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int j=1;j<=m;j++) cin>>b[j];
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        int mx=0;
        for(int j=1;j<=m;j++){
            dp[i][j]=dp[i-1][j];
            if(b[j]<a[i]&&dp[i-1][j]>mx) mx=dp[i-1][j];
            if(a[i]==b[j]&&mx+1>dp[i][j]) dp[i][j]=mx+1;
        }
    }
    int kq=0;
    for(int j=1;j<=m;j++) if(dp[n][j]>kq) kq=dp[n][j];
    cout<<kq;
    return 0;
}
