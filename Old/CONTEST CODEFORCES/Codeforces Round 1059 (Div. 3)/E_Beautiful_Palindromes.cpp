/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
void hoathang(){
    long long n, k;
    cin >> n >> k;
    vector<long long> a;
    a.resize(n);
    vector<long long> pos;
    pos.resize(n + 1, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]] = i + 1;
    }
    set<pair<long long, long long>> s;
    for (int i = 1; i <= n; i++){
        s.insert({pos[i], i});
    }
    vector<long long> ans;
    for (int i = 0; i < k; i++){
        pair<long long, long long> top = *s.begin();
        s.erase(s.begin());
        long long val = top.second;
        ans.push_back(val);
        s.insert({n + i + 1, val});
    }
    for (int i = 0; i < k; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}