#include <bits/stdc++.h>
using namespace std;
long long c, k;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> c >> k;
    if (k == 0){
        cout << c;
        return 0;
    }
    long long p = 10;
    for (int i = 1; i <= k; i++){
        p*=10;
    }
    long long i = p;
    while (i <= c){
        i+=p;
    }
    cout << i;
    return 0;
}