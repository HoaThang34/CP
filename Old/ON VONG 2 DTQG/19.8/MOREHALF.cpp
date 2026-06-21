#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> g[100005], h[100005];
vector<long long> a;
#define task "MOREHALF"
void xuli1(){
    vector<long long> p(n + 1, -1);
    vector<long long> st;
    p[1] = 0;
    st.push_back(1);
    while(st.size() > 0){
        long long u = st.back();
        st.pop_back();
        for(int k = 0; k < g[u].size(); k++){
            long long v = g[u][k];
            if(p[v] == -1){
                p[v] = u;
                h[u].push_back(v);
                st.push_back(v);
            }
        }
    }
}
long long xuli2(long long u){
    vector<long long> cnt(n + 1, 0);
    long long sz = 0;
    vector<long long> s;
    s.push_back(u);
    while(s.size() > 0){
        long long x = s.back();
        s.pop_back();
        sz++;
        cnt[a[x]]++;
        for(int k = 0; k < h[x].size(); k++) s.push_back(h[x][k]);
    }
    for(int c = 1; c <= n; c++){
        if(cnt[c] > sz / 2){
            return c;
        }
    }
    return -1;
}
void subtask1(){
    while(m--){
        long long u;
        cin >> u;
        cout << xuli2(u) << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i < n; i++){
        long long u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    xuli1();
    subtask1();
    return 0;
}
