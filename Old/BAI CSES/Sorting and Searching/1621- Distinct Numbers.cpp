#include <bits/stdc++.h>
using namespace std;
long long n,x;
set<long long> s;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    while (n--){
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
    return 0;
}