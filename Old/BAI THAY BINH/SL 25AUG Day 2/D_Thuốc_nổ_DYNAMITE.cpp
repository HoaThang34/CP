#include <bits/stdc++.h>
using namespace std;
#define int long long
long long n, m;
vector<int> d;                
vector<vector<int>> g;         
vector<vector<int>> dis; 
void bfs(int s){
    queue<int> q;
    vector<int> dd(n + 1, -1);
    dd[s] = 0;
    q.push(s);
    while(!q.empty()){
        long long u = q.front(); q.pop();
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            if(dd[v] == -1){
                dd[v] = dd[u] + 1;
                q.push(v);
            }
        }
    }
    for(int i = 1; i <= (int)n; i++) dis[s][i] = dd[i];
}
long long subtask1(){
    dis.assign(n + 1, vector<int>(n + 1, 0));
    for(int i = 1; i <= (int)n; i++) bfs(i);          
    vector<int> t;
    for(int i = 1; i <= (int)n; i++) if(d[i]) t.push_back(i);
    if(t.empty()) return 0;
    vector<int> c;
    for(int i = 1; i <= (int)m; i++) c.push_back(i);
    long long ans = (long long)1e18;
    while(true){
        long long mx = 0;
        for(int i = 0; i < t.size(); i++){
            int u = t[i];
            int mn = INT_MAX;
            for(int j = 0; j < c.size(); j++){
                int v = c[j];
                mn = min(mn, dis[u][v]);
            }
            mx = max(mx, (long long)mn);
            if(mx >= ans) break;                    
        }
        ans = min(ans, mx);
        int i = (int)m - 1;
        while(i >= 0 && c[i] == (int)(n - (m - 1 - i))) i--;
        if(i < 0) break;
        c[i]++;
        for(int j = i + 1; j < (int)m; j++) c[j] = c[j - 1] + 1;
    }
    return ans;
}
#define task "DYNAMITE"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    d.assign(n + 1, 0);
    for(int i = 1; i <= (int)n; i++){
        int x; cin >> x; d[i] = x;
    }
    g.assign(n + 1, vector<int>());
    for(int i = 1; i < (int)n; i++){
        int a, b; cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cout << subtask1();
    return 0;
}