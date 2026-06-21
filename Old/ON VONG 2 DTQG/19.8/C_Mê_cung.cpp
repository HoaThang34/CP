#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<vector<char>> r, d;
vector<vector<bool>> vs;
#define task "sol"
bool check(char x, long long mask){
    if(x == 'P' && ((mask >> 0) & 1)) return true;
    if(x == 'C' && ((mask >> 1) & 1)) return true;
    if(x == 'Z' && ((mask >> 2) & 1)) return true;
    if(x == 'N' && ((mask >> 3) & 1)) return true;
    return false;
}
bool check1(long long x, long long y){
    return x >= 1 && x <= n && y >= 1 && y <= m;
}
void xuli(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            vs[i][j] = false;
        }
    }
}
bool bfs(long long x, long long y, long long u, long long v, long long mask){
    xuli();
    queue<pair<long long, long long>> q;
    q.push({x, y});
    while(q.size() > 0){
        long long cx = q.front().first;
        long long cy = q.front().second;
        q.pop();
        if(vs[cx][cy]) continue;
        vs[cx][cy] = true;
        if(check1(cx + 1, cy) && !vs[cx + 1][cy] && check(d[cx][cy], mask)){
            q.push({cx + 1, cy});
        }
        if(check1(cx - 1, cy) && !vs[cx - 1][cy] && check(d[cx - 1][cy], mask)){
            q.push({cx - 1, cy});
        }
        if(check1(cx, cy + 1) && !vs[cx][cy + 1] && check(r[cx][cy], mask)){
            q.push({cx, cy + 1});
        }
        if(check1(cx, cy - 1) && !vs[cx][cy - 1] && check(r[cx][cy - 1], mask)){
            q.push({cx, cy - 1});
        }
    }
    return vs[u][v];
}
long long dem(long long mask){
    long long d = 0;
    for(int i = 0; i < 4; i++){
        if((mask >> i) & 1) d++;
    }
    return d;
}
long long xuli1(long long x, long long y, long long u, long long v){
    long long ans = 4;
    for(int mask = 0; mask < 16; mask++){
        if(bfs(x, y, u, v, mask)){
            long long d = dem(mask);
            if(d < ans) ans = d;
        }
    }
    return ans;
}
void subtask1(){
    long long q;
    cin >> q;
    while(q--){
        long long x, y, u, v;
        cin >> x >> y >> u >> v;
        cout << xuli1(x, y, u, v) << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    r.resize(n + 1);
    d.resize(n + 1);
    vs.resize(n + 1);
    for(int i = 0; i <= n; i++){
        r[i].resize(m + 1);
        d[i].resize(m + 1);
        vs[i].resize(m + 1);
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m - 1; j++){
            cin >> r[i][j];
        }
    }
    for(int i = 1; i <= n - 1; i++){
        for(int j = 1; j <= m; j++){
            cin >> d[i][j];
        }
    }
    subtask1();
    return 0;
}