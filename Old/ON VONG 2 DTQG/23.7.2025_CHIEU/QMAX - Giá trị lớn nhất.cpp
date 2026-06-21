#include <bits/stdc++.h>
using namespace std;
long long n, m, q;
vector <long long> a, b;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> m;
    a.resize(n + 1 , 0);
    for (int i = 1; i <= m; i++){
      long long u, v, k;
      cin >> u >> v >> k;
      for (int j = u; j <= v; j++){
        a[j] += k;
      }
    }
    cin >> q;
    while (q--){
      long long rmax= LLONG_MIN;
      long long u, v;
      cin >> u >> v;
      for (int i = u; i <= v; i++){
        rmax = max(rmax, a[i]);
      }
      cout << rmax << endl;
    }
    return 0;
}