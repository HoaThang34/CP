#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vell vector<ll>
long long n;
const int NMAX = 10000001;
bool check(long long x){
    long long s = sqrt(x);
    return s * s == x;
}
void subtask1(){
    int d = 0;
    for (long long i = 1; i <= n; i++){
        for (long long j = i + 1; j <= n; j++){
            for (long long k = j + 1; k <= n; k++){
                if (check(i * j) && check(j * k) && check(i * k)){
                    d++;
                    // cout << i << " " << j << " " << k << endl;
                }
            }
        }
    }
    cout << d;
}
void subtask2(){
    vector<bool> check1(n * n + 1, false);
    for (ll i = 1; i * i <= n * n; i++){
        check1[i * i] = true;
    }
    int d = 0;
    for (ll i = 1; i <= n; i++){
        for (ll j = i + 1; j <= n; j++){
            if (!check1[i * j]) continue;
            for (ll k = j + 1; k <= n; k++){
                if (check1[j * k] && check1[i * k]){
                    d++;
                }
            }
        }
    }
    cout << d;
}
void subtask3(){
    unordered_map<int, int> m;
    vector<int> f(NMAX);
    ll res = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 2; i * i <= n; i++) {
        int ii = i * i;
        for (int j = ii; j <= n; j += ii) {
            while (f[j] % ii == 0) {
                f[j] /= ii;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ++m[f[i]];
    }
    for (auto &i : m) {
        int c = i.second;
        if (c >= 3) {
            res += (ll) c * (c - 1) * (c - 2) / 6;
        }
    }
    cout << res;
}
#define task "triple"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    // subtask1();
    // subtask2();
    subtask3();
    return 0;
}