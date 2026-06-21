#include <bits/stdc++.h>
using namespace std;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    for(int k = 1; k <= n; k++){
        if(n % k == 0){
            bool ok = true;
            for(int i = 0; i < n; i++){
                if(a[i] != a[i % k]){
                    ok = false;
                    break;
                }
            }
            if(ok){
                cout << k << endl;
                return 0;
            }
        }
    }
    
    return 0;
}