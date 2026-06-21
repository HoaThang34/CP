/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "DUONGDEP"
int n, k;
vector <int> a;
void sub1(){
    long long ans = 0; int pos = 0;
    vector <long long> f(n + 5, 0);
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = i; j <= n; j++){
            long long s = f[j] - f[i - 1];
            int len = j - i + 1;
            long long av = s/len;
//            cerr << s << ' ' << len;
            if (av == k){
                if (ans < len) {
                    ans = len;
                    pos = i;
                }
            }
        }
    }
    if (pos == 0 && ans == 0) cout << 0 << endl;
    else cout << pos << ' ' << ans << endl;
//    cerr << pos <<  ' ' << ans << endl;
}
void sub2(){
    long long ans = 0; int pos = 0;
    vector <long long> f(n + 5, 0);
    vector <int> cnt(N, 0);

    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i] - k;
        if (cnt[f[i]] > 0){
            int len = i - cnt[f[i]];
            if (len > ans){
                ans = len;
                pos = cnt[f[i]] + 1;
            }
        } else {
            cnt[f[i]] = i;
        }
    }
    if (pos == 0 && ans == 0) cout << 0 << endl;
    else cout << pos << ' ' << ans << endl;
}
void hoathang(){
    cin >> n >> k;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
//    sub1();
//    sub2();
//    sub2();
    if (n <= 5000) sub1();
    else sub2();
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
