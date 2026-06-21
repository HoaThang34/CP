#include <bits/stdc++.h>
using namespace std;
long long n, l, r, k;
vector <long long> a;
void subtask1(){
  sort(a.rbegin(), a.rend());
  long long d = r - l;
  long long sum = 0;
  for (int i = 0; i <= d; i++){
    sum += a[i];
  }
  cout << sum;
  // for (long long x : a) cout << x << ' ';
}
#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> l >> r >> k;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  subtask1();
  return 0;
}
