#include <bits/stdc++.h>
using namespace std;
long long l, r;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> l >> r;
    while (l <= r){
        cout << l << ' ';
        l++;
    }    
    
    return 0;
}