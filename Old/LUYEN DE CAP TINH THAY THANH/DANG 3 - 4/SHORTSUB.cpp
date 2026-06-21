/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap ""
#define int long long
int n, s;
vector<int> a;
vector<long long> f;
void hoathang(){
    cin >> n>> s;
    a.resize(n + 5);
    f.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        f[i] = f[i - 1] + a[i];
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            long long sum = f[j] - f[i - 1];
            if (sum >= s){
                ans = min(ans, j - i + 1);
            }
        }
    }
    if (ans == 1e9) cout << 0 << endl;
    else cout << ans << endl;
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
