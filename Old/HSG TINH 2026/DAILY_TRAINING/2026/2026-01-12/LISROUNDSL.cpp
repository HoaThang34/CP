/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "LISROUNDSL"

int n;
long long s;
vector<int> a;
void hoathang(){
    cin >> n >> s;
    a.resize(2 * n + 5);
    long long sum = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        a[i + n] = a[i];
        sum += a[i];
    }
    if (sum < s){
        cout << -1 << endl;
        return;
    }
    int l = 1, ans = n + 1;
    long long res = 0;
    for (int r = 1; r <= 2 * n; r++){
        res += a[r];
        while (res >= s){
            if (r - l + 1 <= n){
                ans = min(ans, r - l + 1);
            }
            res -= a[l];
            l++;
        }
    }
    if (ans > n) cout << -1 << endl;
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
