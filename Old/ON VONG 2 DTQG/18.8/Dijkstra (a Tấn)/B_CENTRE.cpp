#include <bits/stdc++.h>
using namespace std;
long long n, m;
const long long MOD = 1e9+7;
vector<pair<long long, long long>> adj[30005];
#define task "sol"
long long dijkstra(long long s, long long t, long long val){
    vector<long long> d(n + 1, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    if(s == val || t == val) return LLONG_MAX;
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        long long dt = pq.top().first;
        long long u = pq.top().second;
        pq.pop();
        if(dt != d[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            long long v = adj[u][i].first;
            long long w = adj[u][i].second;
            if(v == val) continue;
            if(d[v] > (dt + w) % MOD){
                d[v] = (dt + w) % MOD;
                pq.push({d[v], v});
            }
        }
    }
    return d[t];
}
void subtask1(){
    long long d = dijkstra(1, n, -1);
    vector<long long> ans;
    for(int i = 2; i < n; i++){
        long long c = dijkstra(1, n, i);
        if(c == d){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}
vector<long long> d1, d2;
void dijkstra1(){
    d1.assign(n + 1, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    d1[1] = 0;
    pq.push({0, 1});
    while(!pq.empty()){
        long long dt = pq.top().first, u = pq.top().second;
        pq.pop();
        if(dt != d1[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            long long v = adj[u][i].first, w = adj[u][i].second;
            if(d1[v] > (dt + w) % MOD){
                d1[v] = (dt + w) % MOD;
                pq.push({d1[v], v});
            }
        }
    }
}
void dijkstra2(){
    d2.assign(n + 1, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    d2[n] = 0;
    pq.push({0, n});
    while(!pq.empty()){
        long long dt = pq.top().first, u = pq.top().second;
        pq.pop();
        if(dt != d2[u]) continue;
        for(int i = 0; i < adj[u].size(); i++){
            long long v = adj[u][i].first, w = adj[u][i].second;
            if(d2[v] > (dt + w) % MOD){
                d2[v] = (dt + w) % MOD;
                pq.push({d2[v], v});
            }
        }
    }
}
void subtask2(){
    dijkstra1();
    dijkstra2();
    long long d = d1[n];
    vector<long long> ans;
    for(int i = 2; i < n; i++){
        if((d1[i] + d2[i]) % MOD > d){
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        long long u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    if(n <= 2000) subtask1();
    else subtask2();
    return 0;
}
