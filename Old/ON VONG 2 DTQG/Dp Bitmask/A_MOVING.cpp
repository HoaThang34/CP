#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("sol.inp", "r")) {
        freopen("sol.inp", "r", stdin);
        freopen("sol.out", "w", stdout);
    }
    
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }
    
    vector<long long> timeToNodes(n + 1, LLONG_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    
    // Thắng xuất phát từ đỉnh 1
    timeToNodes[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        long long currentTime = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (currentTime != timeToNodes[u]) continue;
        
        for (auto &edge : graph[u]) {
            int v = edge.first;
            long long w = edge.second;
            if (timeToNodes[v] > currentTime + w) {
                timeToNodes[v] = currentTime + w;
                pq.push({timeToNodes[v], v});
            }
        }
    }
    
    for (int i = 2; i <= n; ++i) {
        if (timeToNodes[i] == LLONG_MAX) cout << -1 << " ";
        else cout << timeToNodes[i] << " ";
    }
    
    return 0;
}