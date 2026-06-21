#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector <long long> a, b;

#define task "calo"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> b[i];
    }    
    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; i++){
        if (b[i] <= k){
            sum = sum + a[i];
        }
        else{
            sum = 0;
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}