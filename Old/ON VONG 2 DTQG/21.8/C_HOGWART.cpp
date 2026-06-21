#include <bits/stdc++.h>
using namespace std;
long long dem;
vector<vector<vector<long long>>> g;
vector<long long> l;
vector<long long> par;
void add(long long u, long long v, long long c){
    g[u].push_back({v, c, (long long)g[v].size()});
    g[v].push_back({u, 0, (long long)g[u].size() - 1});
}
bool bfs(long long s, long long t){
    for(long long i = 0; i < dem; ++i){
        l[i] = -1;
    }
    queue<long long> q;
    q.push(s);
    l[s] = 0;
    while(!q.empty()){
        long long v = q.front();
        q.pop();
        for(vector<long long> e : g[v]){
            if(e[1] > 0 && l[e[0]] == -1){
                l[e[0]] = l[v] + 1;
                q.push(e[0]);
            }
        }
    }
    return l[t] != -1;
}
long long dfs(long long v, long long t, long long sum){
    if(v == t || sum == 0){
        return sum;
    }
    for(long long &i = par[v]; i < (long long)g[v].size(); ++i){
        vector<long long> &e = g[v][i];
        if(l[e[0]] == l[v] + 1 && e[1] > 0){
            long long ti = dfs(e[0], t, min(sum, e[1]));
            if(ti > 0){
                e[1] -= ti;
                g[e[0]][e[2]][1] += ti;
                return ti;
            }
        }
    }
    return 0;
}
long long xuli(long long s, long long t){
    long long f = 0;
    while(bfs(s, t)){
        for(long long i = 0; i < dem; ++i){
            par[i] = 0;
        }
        while(long long sum = dfs(s, t, LLONG_MAX)){
            f += sum;
        }
    }
    return f;
}
#define task "hogwart"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    while(true){
        long long n, m;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        vector<string> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        dem = n * m * 2;
        g.assign(dem, vector<vector<long long>>());
        l.resize(dem);
        par.resize(dem);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] == '#'){
                    continue;
                }
                long long in = (i * m + j) * 2;
                long long out = (i * m + j) * 2 + 1;
                long long pos = (a[i][j] == '@' ? LLONG_MAX : 1);
                add(in, out, pos);
                long long dx[4] = {0, 0, 1, -1};
                long long dy[4] = {1, -1, 0, 0};
                for(int k = 0; k < 4; k++){
                    long long ni = i + dx[k];
                    long long nj = j + dy[k];
                    if(ni >= 0 && ni < n && nj >= 0 && nj < m && a[ni][nj] != '#'){
                        long long new1 = (ni * m + nj) * 2;
                        add(out, new1, LLONG_MAX);
                    }
                }
            }
        }
        long long new2 = (0 * m + 0) * 2;
        long long new3 = ((n - 1) * m + (m - 1)) * 2 + 1;
        long long ans = xuli(new2, new3);
        if(ans >= LLONG_MAX / 2){
            cout << -1 << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}