#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, q;
vector<vector<long long>> g;
vector<pair<long long, long long>> edge;
vector<tuple<long long, long long, long long>> check;
long long sum;
#define task "sol"
bool find(long long u, long long p, long long t, const vector<long long>& cnt){
    if(u == t){
        return true;
    }
    for(long long i = 0; i < g[u].size(); i++){
        long long v = g[u][i];
        if(v == p){
            continue;
        }
        if(find(v, u, t, cnt)){
            long long w = -1;
            for(int j = 0; j < edge.size(); j++){
                if((edge[j].first == u && edge[j].second == v) || (edge[j].first == v && edge[j].second == u)){
                    w = j;
                    break;
                }
            }
            sum += cnt[w];
            return true;
        }
    }
    return false;
}
void subtask1(){
    cin >> n >> q;
    g.assign(n + 1, vector<long long>());
    edge.clear();
    check.clear();
    for(int i = 0; i < n - 1; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        edge.push_back({u, v});
    }
    for(int i = 0; i < q; i++){
        long long u, v, x;
        cin >> u >> v >> x;
        check.emplace_back(u, v, x);
    }
    long long ans = 0;
    long long cnt = (1LL << (n - 1));
    for(long long mask = 0; mask < cnt; mask++){
        vector<long long> cnt(n - 1);
        for(int i = 0; i < n - 1; i++){
            if((mask >> i) & 1){
                cnt[i] = 1;
            } else{
                cnt[i] = 0;
            }
        }
        bool check1 = true;
        for(int i = 0; i < q; i++){
            long long u = get<0>(check[i]);
            long long v = get<1>(check[i]);
            long long x = get<2>(check[i]);
            sum = 0;
            find(u, 0, v, cnt);
            if(sum % 2 != x){
                check1 = false;
                break;
            }
        }
        if(check1){
            ans = (ans + 1) % MOD;
        }
    }
    cout << ans << endl;
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    long long t;
    cin >> t;
    while(t--){
        subtask1();
    }
    return 0;
}