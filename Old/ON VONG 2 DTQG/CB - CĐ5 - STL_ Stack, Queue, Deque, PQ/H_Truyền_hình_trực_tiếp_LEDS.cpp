#include <bits/stdc++.h>
using namespace std;
long long n, k, l, r, sg_dist;
vector<long long> a, T, s;
vector<vector<long long>> f;
#define task "leds"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k >> l >> r >> sg_dist;
    a.resize(n + 1);
    s.resize(n + 1, 0);
    T.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++){
        long long val = (long long)(i - 1) * a[i] - s[i - 1];
        val += (s[n] - s[i]) - (long long)(n - i) * a[i];
        T[i] = val;
    }
    f.assign(k + 1, vector<long long>(n + 1, -1e18));
    for(int i = 1; i <= n; i++){
        if(a[i] >= l && a[i] <= r){
            f[1][i] = T[i];
        }
    }
    for(int j = 2; j <= k; j++){
        deque<long long> dq;
        long long p = 1;
        for(int i = 1; i <= n; i++){
            for(; p < i && a[p] <= a[i] - l; p++){
                if(f[j - 1][p] > -1e17){
                    while(!dq.empty() && f[j - 1][dq.back()] <= f[j - 1][p]){
                        dq.pop_back();
                    }
                    dq.push_back(p);
                }
            }
            while(!dq.empty() && a[dq.front()] < a[i] - r){
                dq.pop_front();
            }
            if(!dq.empty()){
                f[j][i] = T[i] + f[j - 1][dq.front()];
            }
        }
    }
    long long ans = -1;
    for(int i = 1; i <= n; i++){
        if(sg_dist - a[i] >= l && sg_dist - a[i] <= r){
            if(f[k][i] > -1e17){
                ans = max(ans, f[k][i]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}