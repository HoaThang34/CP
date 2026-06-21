/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "E"
int n, m, k;
vector<int> a, b;
vector<int> f, dt;
string s;
void hoathang(){
    cin >> n >> m >> k;
    a.resize(n + 5);
    b.resize(m + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i= 1; i <= m; i++){
        cin >> b[i];
    }
    sort(b.begin() + 1, b.begin() + m + 1);
    cin >> s;
    f.assign(2*k + 5, k + 1);
    int d = 0;
    for (int i = 1; i <= k; i++){
        if (s[i - 1] == 'L') d++;
        else d--;
        if (f[d + k] > k){
            f[d + k] = i;
        }
    }
    dt.clear();
    for (int i=  1; i <= n; i++){
        int t = k + 1;
        auto it = lower_bound(b.begin() + 1, b.begin() + m + 1, a[i]);
        if (it!=b.begin() + 1+ m){
            long long v = a[i] - *it;
            if (v >= -k && v <= k){
                t= min(t, f[v + k]);
            }
        }
        if (it!=b.begin() + 1){
            auto it1 = prev(it);
            long long v = a[i] - *it1;
            if (v >= -k && v <= k)
            t = min(t, f[v + k]);
        }
        if (t <= k) dt.push_back(t);
    }
    sort(dt.begin(), dt.end());
    int p = 0;
    for (int i=  1; i <= k; i++){
        while (p < dt.size() && dt[p] <= i) p++;
        cout << n - p << ' ';
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--)
        hoathang();
    return 0;
}
