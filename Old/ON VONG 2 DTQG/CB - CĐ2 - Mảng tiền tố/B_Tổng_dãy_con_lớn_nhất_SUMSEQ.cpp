#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, q;
vector <ll> a;
vector <ll> pre;
#define task "SUMSEQ"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    pre.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pre[i] = pre[i - 1] + max(0LL, a[i]);
    }
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}