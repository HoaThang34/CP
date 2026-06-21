#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define task "sol"

const int N = 2e5 + 5;
int n, a[N], popcount[N];
vector<int> adj[N], gr[20];
bool ok[N];

int bfs(int st, const vector<int> &nhom){
    queue<int> q;
    vector<int> d(n + 1, -1);
    q.push(st); d[st] = 0;
    int u = st;

    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int x : adj[v]){
            if (d[x] == -1){
                d[x] = d[v] + 1;
                q.push(x);
                if (ok[x] && d[x] > d[u]) u = x;
            }
        }
    }

    q.push(u);
    fill(d.begin(), d.end(), -1);
    d[u] = 0;
    int res = 0;

    while (!q.empty()){
        int v = q.front(); q.pop();
        for (int x : adj[v]){
            if (d[x] == -1){
                d[x] = d[v] + 1;
                q.push(x);
                if (ok[x]) res = max(res, d[x]);
            }
        }
    }

    return res;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }

    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        int c = __builtin_popcount(a[i]);
        popcount[i] = c;
        gr[c].push_back(i);
    }

    for (int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 0;
    for (int i = 0; i < 20; i++){
        if (gr[i].size() < 2) continue;
        for (int u : gr[i]) ok[u] = 1;
        ans = max(ans, bfs(gr[i][0], gr[i]));
        for (int u : gr[i]) ok[u] = 0;
    }

    cout << ans << '\n';
    return 0;
}
