#include <bits/stdc++.h>
using namespace std;
long long n, q, l, r;
vector <long long> a;
vector <long long> pre;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> q;
    a.resize(n + 1);
    pre.resize (n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i<= n; i++){
        pre[i] = pre[i - 1] + a[i];
    }
    while (q--){
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}