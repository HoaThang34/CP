#include <bits/stdc++.h>
using namespace std;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp","r")){
        freopen(task".inp","r",stdin);
        freopen(task".out","w",stdout);
    }
    int t; cin >> t;
    while(t--){
        int n; long long k;
        cin >> n >> k;
        vector<long long> s(n), tt(n);
        for(int i=0;i<n;i++) cin >> s[i];
        for(int i=0;i<n;i++) cin >> tt[i];
        if(k==0){
            sort(s.begin(), s.end());
            sort(tt.begin(), tt.end());
            cout << (s==tt ? "YES\n" : "NO\n");
            continue;
        }
        map<pair<long long,long long>, int> cnt;
        for(int i=0;i<n;i++){
            long long r = s[i] % k;
            long long r2 = (k - r) % k;
            long long mn = min(r, r2);
            long long mx = max(r, r2);
            cnt[{mn, mx}]++;
        }
        for(int i=0;i<n;i++){
            long long r = tt[i] % k;
            long long r2 = (k - r) % k;
            long long mn = min(r, r2);
            long long mx = max(r, r2);
            cnt[{mn, mx}]--;
        }
        bool ok = 1;
        for(auto &p: cnt){
            if(p.second != 0){ok=0; break;}
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
