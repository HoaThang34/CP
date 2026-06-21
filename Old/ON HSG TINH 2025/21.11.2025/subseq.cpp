/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"
long long n;
vector <long long> a;
long long gcd(long long a, long long b){
    long long tmp;
    while (b > 0){
        tmp = a% b;
        a = b;
        b = tmp;
    }
    return a;
}
bool check(long long u, long long v){
    int q = a[u];
    for (int i = u + 1; i <=  v; i++){
        q = gcd(q, a[i]);
    }
    if (q > 1){
        return true;
    }
    return false;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (check(i, j)){
                ans = max(ans, (long long)j - i + 1);
            }
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
