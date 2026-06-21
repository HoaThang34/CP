#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector <long long> a, b;
vector <long long> dp;
#define task "market"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> m;
  a.resize(n + 1);
  b.resize(m + 1); 
  dp.resize(n + 1, LLONG_MAX);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++){
    cin >> b[i];
  }
  for (int w = m - 1; w >= 1; w--) b[w] = min(b[w], b[w + 1]);
  sort(a.begin() + 1, a.end());
  dp[0] = 0;
  for (int i = 1; i <= n; i++){
    for (int j = 0; j < i; j++){
      long long w = a[i] - a[j + 1] + 1;
      if (w > m) continue;
      dp[i] = min(dp[i], dp[j] + b[w]);
      
    }
  }
  cout << dp[n];
  return 0;
}
