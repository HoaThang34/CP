#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector<long long> color;
vector<vector<long long>> g;
vector<long long> par;
vector<map<long long, long long>> cnt;
long long find(long long u){
    if(par[u] == u){
        return u;
    }
    return par[u] = find(par[u]);
}
void union_set(long long u, long long v){
    long long paru = find(u);
    long long parv = find(v);
    if(paru == parv){
        return;
    }
    if(cnt[paru].size() < cnt[parv].size()){
        swap(paru, parv);
    }
    for(pair<long long, long long> x : cnt[parv]){
        cnt[paru][x.first] += x.second;
    }
    par[parv] = paru;
}
void subtask1(){
    g.resize(n + 1);
    for(int i = 0; i < q; i++){
        long long loai;
        cin >> loai;
        if(loai == 1){
            long long u, v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        else{
            long long u, c;
            cin >> u >> c;
            long long d = 0;
            vector<bool> vs(n + 1, false);
            queue<long long> q;
            q.push(u);
            vs[u] = true;
            while(!q.empty()){
                long long v = q.front();
                q.pop();
                if(color[v] == c){
                    d++;
                }
                for(long long t : g[v]){
                    if(!vs[t]){
                        vs[t] = true;
                        q.push(t);
                    }
                }
            }
            cout << d << endl;
        }
    }
}
void subtask2(){
    par.resize(n + 1);
    cnt.resize(n + 1);
    for(long long i = 1; i <= n; i++){
        par[i] = i;
        cnt[i][color[i]] = 1;
    }
    for(int i = 0; i < q; i++){
        long long loai;
        cin >> loai;
        if(loai == 1){
            long long u, v;
            cin >> u >> v;
            union_set(u, v);
        }
        else{
            long long u, c;
            cin >> u >> c;
            long long paru = find(u);
            if(cnt[paru].count(c)){
                cout << cnt[paru][c] << endl;
            }
            else{
                cout << 0 << endl;
            }
        }
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> q;
    color.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> color[i];
    }
    if(n <= 1000 && q <= 1000){
        subtask1();
    }
    else{
        subtask2();
    }
    return 0;
}