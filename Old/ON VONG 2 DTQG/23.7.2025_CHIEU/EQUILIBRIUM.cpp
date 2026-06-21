#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
vector <long long> f;
#define task "EQUILIBRIUM"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    a.resize(n + 1);
    f.resize(n + 1, 0);
    for (int i = 1; i <= n; i++){
      cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
      f[i] = f[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++){
      long long s1 = f[i] - f[0];
      long long s2 = f[n] - f[i - 1];
      if (s1 == s2){
        cout << i;
        return 0;
      }
    }
    cout << -1;
    return 0;
}