#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<int> p;
void make_set(int v){
    p[v] = v;
}
int find_set(int v){
    if (v == p[v]) return v;
    return p[v] = find_set(p[v]);
}
void union_sets(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a != b) p[b] = a;
}
#define task "XD"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    vector<pair<long long, long long>> g(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> g[i].first >> g[i].second;
    }
    vector<pair<double, pair<int, int>>> adj;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            long long dx = g[i].first - g[j].first;
            long long dy = g[i].second - g[j].second;
            double dis = sqrt(dx * dx + dy * dy);
            adj.push_back({dis, {i, j}});
        }
    }
    p.resize(n + 1);
    for(int i = 1; i <= n; i++){
        make_set(i);
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        if(find_set(u) != find_set(v)){
            union_sets(u, v);
            cnt++;
        }
    }
    sort(adj.begin(), adj.end());
    double ans = 0;
    for(int i = 0; i < adj.size(); i++){
        if(cnt == n - 1) break;
        double w = adj[i].first;
        int u = adj[i].second.first;
        int v = adj[i].second.second;
        if(find_set(u) != find_set(v)){
            ans += w;
            union_sets(u, v);
            cnt++;
        }
    }
    cout << fixed << setprecision(3) << ans;
    return 0;
}