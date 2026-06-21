/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "NSQUASL"
int n;
vector<int> f, cnt;
void hoathang(){
    cin >> n;
    f.resize(n + 5);
    cnt.resize(n + 5, 0);
    for (int i = 1; i <= n; i++){
        f[i] = i;
    }
    for (long long i = 2; i * i <= n; i++){
        for (int j = i*i; j <= n; j += (i*i)){
            while (f[j] % (i*i) == 0) f[j] /= (i*i);
        }
    }
    for (int i = 1; i <= n; i++) cnt[f[i]]++;
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        if (cnt[i] >= 3){
            long long k = cnt[i];
            ans += k * (k - 1) * (k - 2) / 6;
        }
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
