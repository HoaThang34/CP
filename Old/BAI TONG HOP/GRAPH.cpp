/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n, m;
vector<pair<long long, long long>> g;
vector<vector<long long>> adj;
vector<long long> dis;

vector<double> xuli(vector<vector<double>> a, vector<double> b){
    long long len = a.size();
    for (long long i = 0; i < len; i++) {
        long long p = i;
        for (long long j = i + 1; j < len; j++){
            if (abs(a[j][i]) > abs(a[p][i])){
                p = j;
            }
        }
        swap(a[i], a[p]);
        swap(b[i], b[p]);
        double k = a[i][i];
        for (long long j = i; j < len; j++) {
            a[i][j] /= k;
        }
        b[i] /= k;
        for (long long j = 0; j < len; j++) {
            if (i != j) {
                double d = a[j][i];
                for (long long k = i; k < len; k++) {
                    a[j][k] -= d * a[i][k];
                }
                b[j] -= d * b[i];
            }
        }
    }
    return b;
}

void hoathang(){
    cin >> n >> m;
    adj.resize(n + 1);
    dis.assign(n + 1, 0);
    g.resize(m);
    for (long long i = 0; i < m; i++) {
        long long u, v;
        cin >> u >> v;
        g[i] = {u, v};
        adj[u].push_back(v);
        adj[v].push_back(u);
        dis[u]++;
        dis[v]++;
    }
    if (n == 1) {
        cout << "0.000" << endl;
        return;
    }
    long long len = n - 1;
    vector<vector<double>> a(len, vector<double>(len, 0.0));
    vector<double> b(len, 0.0);
    for (long long i = 0; i < len; i++) {
        a[i][i] = 1.0;
    }
    if (len > 0) {
        b[0] = 1.0;
    }
    for (long long u = 1; u < n; u++) {
        for (long long v : adj[u]) {
            if (v < n) {
                a[v - 1][u - 1] -= 1.0 / dis[u];
            }
        }
    }
    vector<double> x;
    if (len > 0) {
        x = xuli(a, b);
    }
    vector<double> f;
    for (const auto& y : g) {
        long long u = y.first;
        long long v = y.second;
        double res2 = 0.0;
        if (u < n) {
            res2 = x[u - 1];
        }
        double res1 = 0.0;
        if (v < n) {
            res1 = x[v - 1];
        }
        if (dis[u] > 0 && dis[v] > 0) {
            double cnt = (res2 / dis[u]) + (res1 / dis[v]);
            f.push_back(cnt);
        }
        else {
            f.push_back(0.0);
        }
    }
    sort(f.rbegin(), f.rend());
    double ans = 0;
    for (long long i = 0; i < m; i++) {
        ans += f[i] * (i + 1);
    }
    cout << fixed << setprecision(3) << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    long long t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}


