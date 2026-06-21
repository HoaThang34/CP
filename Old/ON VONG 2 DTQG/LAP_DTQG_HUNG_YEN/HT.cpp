#include <bits/stdc++.h>
using namespace std;
struct HT{
    long long s, e;
};
bool cmp(const HT& x, const HT& y){
    if(x.e != y.e){
        return x.e < y.e;
    }
    return x.s < y.s;
}
long long n;
vector<HT> v;
vector<long long> f, g;
#define task "HT"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".INP", "r")){
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++){
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        v[i].s = min(a, c);
        v[i].e = max(b, d);
    }
    sort(v.begin(), v.end(), cmp);
    f.resize(n + 1, 0);
    g.resize(n + 1, 0);
    g[0] = 1;
    vector<long long> ans;
    for(int i = 1; i <= n; i++){
        long long s_i = v[i - 1].s;
        long long p = lower_bound(ans.begin(), ans.end(), s_i) - ans.begin();
        long long new1 = f[p] + 1;
        long long cnt1 = g[p];
        if(new1 > f[i - 1]){
            f[i] = new1;
            g[i] = cnt1;
        } else if(new1 < f[i - 1]){
            f[i] = f[i - 1];
            g[i] = g[i - 1];
        } else{
            f[i] = f[i - 1];
            g[i] = (g[i - 1] + cnt1) % 2023;
        }
        ans.push_back(v[i - 1].e);
    }
    cout << f[n] << " " << g[n];
    return 0;
}