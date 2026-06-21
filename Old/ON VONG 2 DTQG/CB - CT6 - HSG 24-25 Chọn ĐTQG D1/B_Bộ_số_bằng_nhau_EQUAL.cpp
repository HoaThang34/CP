#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
long long n, t, k;
vector <long long> a;
map <long long, long long> mp;
long long C(long long k, long long n){
    if (k < 0 || k > n){
        return 0;
    } 
    if (k == 0 || k == n){
        return 1;
    }
    if (n/2 < k){
        k = n - k;
    }
    long long ans = 1;
    for(long long i = 1; i <= k; i++){
        ans = ans * (n - i + 1)/i;
    }
    return ans;
}
void subtask1(){
    long long d = 0;
    for (pair <long long, long long> x : mp){
        // cerr << x.first << ' ' << x.second << endl;
        if (x.second < k){
            continue;
        }
        else if (x.second == k){
            d = (d + 1) % MOD;
        }
        else{
            d = (d + (C(k, x.second) % MOD)) % MOD;
        }
    }
    cout << d % MOD << endl;
}
#define task "EQUAL"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> t;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
    while (t--){
        cin >> k;
        subtask1();
    }
    return 0;
}