#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, k;
vector <long long> a;
long long s = 0;
void xuli(long long x, vector <long long> &b){
    if (b.size() == k){
        long long rmax = LLONG_MIN;
        // for (long long k : b) cerr << k << ' ';
        // cerr << endl;
        for (long long x : b){
            rmax = max(rmax, x);
        }
        s += rmax;
        s % MOD;
        return;
    }
    else{
        for (int i = x; i <= n; i++){
            b.push_back(a[i]);
            xuli(i + 1, b);
            b.pop_back();
        }
    }
}
#define task "PIANO"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    vector <long long> b;
    xuli(1, b);
    cout << s;
    return 0;   
}