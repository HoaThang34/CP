/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "BPAIR"
const int N = 1e6 + 5;
vector<long long> f(N + 5, 1);

void sang(){
    for (int i = 2; i <= N; i++){
        if (f[i] == 1){
            for (int j = i; j <= N; j+=i){
                f[j] *= i;
            }
        }
    }
}
long long p, q;
void hoathang(){
    sang();
    cin >> p >> q;
    map<long long, long long> cnt;
    for (int i = p; i <= q; i++){
        cnt[f[i]]++;
    }
    long long ans = 0;
    for (pair <long long, long long> x : cnt){
        long long c = x.second;
        ans += c * (c - 1) / 2;
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
