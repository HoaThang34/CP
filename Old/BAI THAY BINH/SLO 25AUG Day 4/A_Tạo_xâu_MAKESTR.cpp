#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX;
long long n, m;
string s, t;
vector<vector<int>> pos;
vector<long long> dp;
#define task "MAKESTR"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    cin >> s >> t;
    pos.resize(26);
    for(int i = 0; i < n; i++){
        pos[s[i] - 'a'].push_back(i + 1);
    }
    dp.resize(n + 1, INF);
    int x1 = t[0] - 'a';
    for(int p : pos[x1]){
        dp[p] = 0;
    }
    for(int i = 1; i < m; i++){
        vector<long long> dp2(n + 1, INF);
        int x2 = t[i-1] - 'a';
        x1 = t[i] - 'a';
        const auto& p1 = pos[x2];
        const auto& p2 = pos[x1];
        if(p1.empty() || p2.empty()) {
             dp = dp2;
             break;
        }
        long long rmin = INF;
        int ptr = 0;
        for(int p2 : p2){
            while(ptr < p1.size() && p1[ptr] < p2){
                if(dp[p1[ptr]] != INF){
                     rmin = min(rmin, dp[p1[ptr]] - p1[ptr]);
                }
                ptr++;
            }
            if(rmin != INF){
                dp2[p2] = min(dp2[p2], rmin + p2);
            }
        }
        rmin = INF;
        ptr = p1.size() - 1;
        for(int j = p2.size() - 1; j >= 0; j--){
            int cp2 = p2[j];
            while(ptr >= 0 && p1[ptr] > cp2){
                if(dp[p1[ptr]] != INF){
                    rmin = min(rmin, dp[p1[ptr]] + p1[ptr]);
                }
                ptr--;
            }
            if(rmin != INF){
                dp2[cp2] = min(dp2[cp2], rmin - cp2);
            }
        }
        dp = dp2;
    }
    long long ans = INF;
    x1 = t.back() - 'a';
    for(int p : pos[x1]){
        ans = min(ans, dp[p]);
    }
    if(ans == INF){
        cout << -1 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}