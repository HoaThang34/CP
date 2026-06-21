#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <char> a;
bool xuli(long long l, long long r){
  string s = "";
  for (int i = l; i <= r; i++){
    s += a[i];
  }
  string s1 = s;
  reverse(s1.begin(), s1.end());
  return s == s1;
}
#define task "BIENSO"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  while (m--){
    long long k;
    cin >> k;
    if (k == 1){
      long long k;
      char x;
      cin >> k >> x;
      a[k] = x;
    }
    else if (k == 2){
      long long l, r;
      cin >> l >> r;
      if (xuli(l, r)) cout << "YES\n";
      else cout << "NO\n";
    }
  }
  return 0;
}
