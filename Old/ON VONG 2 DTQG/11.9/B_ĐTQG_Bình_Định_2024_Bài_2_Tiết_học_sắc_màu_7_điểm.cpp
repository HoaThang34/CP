#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, l, r;
vector<long long> a;
vector<long long> f;
long long dis(int s, int t){
    set<long long> st;
    for(int i = s; i <= t; i++){
        st.insert(a[i]);
    }
    return st.size();
}
long long dem(int s){
    if(s > n){
        return 1;
    }
    if(f[s] != -1){
        return f[s];
    }
    long long ans = 0;
    for(int i = s; i <= n; i++){
        int d = dis(s - 1, i - 1);
        if(d >= l && d <= r){
            ans = (ans + dem(i + 1)) % MOD;
        }
    }
    return f[s] = ans;
}
void subtask1(){
    cout << dem(1) << '\n';
}
#define task "color"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> l >> r;
    a.resize(n);
    f.resize(n + 2, -1);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    subtask1();
    return 0;
}