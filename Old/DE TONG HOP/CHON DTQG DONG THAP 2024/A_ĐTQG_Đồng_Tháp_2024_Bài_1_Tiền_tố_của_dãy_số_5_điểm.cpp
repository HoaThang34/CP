#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a;

#define task "bai1"
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
    long long s = 0;
    long long ans = LLONG_MIN;
    for (int i = 1; i <= n; i++){
        s += a[i];
        long long x = (s + i) / k * k;
        if (x >= s){
            ans = i;
        }
    }
    cout << ans;
    return 0;
}