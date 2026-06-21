#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;

#define task "pairing"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> a >> b >> c >> d;
  cout << abs(b - d);
  return 0;
}
