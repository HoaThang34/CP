#include <bits/stdc++.h>
using namespace std;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int a[15], b[15];
        for(int i=0;i<n;i++) cin >> a[i];
        for(int i=0;i<n;i++) cin >> b[i];
        int d = 0;
        for(int i=0;i<n;i++){
            if(a[i] > b[i]) d += a[i] - b[i]; 
        }
        cout << d + 1 << '\n'; 
    }
}
