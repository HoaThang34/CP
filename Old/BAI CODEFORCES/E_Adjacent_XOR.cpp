#include <bits/stdc++.h>
using namespace std;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<unsigned int>a(n), b(n);
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        bool ok = true;
        if(a[n-1] != b[n-1]) ok = false;
        for(int i = n-2; ok && i >= 0; i--){
            if(a[i] == b[i]) continue;
            if((a[i] ^ a[i+1]) == b[i]) continue;
            if((a[i] ^ b[i+1]) == b[i]) continue;
            ok = false;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
