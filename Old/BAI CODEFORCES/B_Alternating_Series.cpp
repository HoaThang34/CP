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
        for(int i=1;i<=n;i++){
            if(i%2==1) cout << -1 << ' ';
            else{
                if(i==n) cout << 2 << ' ';
                else cout << 3 << ' ';
            }
        }
        cout << '\n';
    }
}
