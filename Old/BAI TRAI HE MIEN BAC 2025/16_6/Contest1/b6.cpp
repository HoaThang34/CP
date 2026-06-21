#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
const ll MOD = 1000000007;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int n,k;
    cin>>n>>k;
    int N = n + k - 1;
    int K = k - 1;
    ll res = 1;
    if(K > N-K) K = N-K;
    for(int i=1;i<=K;i++){
        res = res * (N - i + 1) / i;
    }
    cout<< res % MOD <<"\n";
    return 0;
}
