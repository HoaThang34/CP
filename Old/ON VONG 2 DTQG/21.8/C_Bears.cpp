#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> a;
vector<long long> par;
vector<long long> vs;
long long find(long long u){
    if(par[u] == u){
        return u;
    }
    return par[u] = find(par[u]);
}
void union_set(long long u, long long v){
    u = find(u);
    v = find(v);
    if(u == v){
        return;
    }
    if(vs[u] < vs[v]){
        swap(u, v);
    }
    par[v] = u;
    vs[u] += vs[v];
}
void subtask1(){
    for(long long x = 1; x <= n; x++){
        long long ans = 0;
        for(long long i = 1; i <= n - x + 1; i++){
            long long rmin = a[i];
            for(long long j = i + 1; j < i + x; j++){
                rmin = min(rmin, a[j]);
            }
            ans = max(ans, rmin);
        }
        cout << ans << " ";
    }
}
void subtask2(){
    for(long long x = 1; x <= n; x++){
        long long ans = 0;
        deque<long long> dq;
        for(long long i = 1; i <= n; i++){
            while(!dq.empty() && a[dq.back()] >= a[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() <= i - x){
                dq.pop_front();
            }
            if(i >= x){
                long long rmin = a[dq.front()];
                ans = max(ans, rmin);
            }
        }
        cout << ans << " ";
    }
}
void subtask3(){
    map<long long, vector<long long>> vt;
    for(long long i = 1; i <= n; i++){
        vt[a[i]].push_back(i);
    }
    par.resize(n + 2);
    vs.resize(n + 2, 1);
    for(long long i = 0; i <= n + 1; i++){
        par[i] = i;
    }
    vector<long long> res(n + 2, 0);
    vector<bool> vis(n + 2, false);
    for(map<long long, vector<long long>>::reverse_iterator it = vt.rbegin(); it != vt.rend(); ++it){
        long long h = it->first;
        for(long long i : it->second){
            vis[i] = true;
            if(vis[i - 1]){
                union_set(i, i - 1);
            }
            if(vis[i + 1]){
                union_set(i, i + 1);
            }
            long long pa = find(i);
            long long dis = vs[pa];
            res[dis] = max(res[dis], h);
        }
    }
    for(long long i = n - 1; i >= 1; --i){
        res[i] = max(res[i], res[i + 1]);
    }
    for(long long i = 1; i <= n; ++i){
        cout << res[i] << " ";
    }
}
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n <= 500){
        subtask1();
    }
    else if(n <= 5000){
        subtask2();
    }
    else{
        subtask3();
    }
    return 0;
}