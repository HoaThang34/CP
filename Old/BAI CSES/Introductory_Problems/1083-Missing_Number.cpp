#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <=n; i++){
        cin >> a[i];
    }
    sort (a.begin(), a.end());
    for (int i = 1; i <= n; i++){
        if (a[i + 1] != a[i] + 1 && a[i] + 1 <= n){
            cout << a[i] + 1 << ' ';
        }
    }
    return 0;
}