#include <bits/stdc++.h>
using namespace std;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long a, b, c;
    cin >> a >> b >> c;
    long long d = a * b;
    cout << d % c;   
    return 0;
}