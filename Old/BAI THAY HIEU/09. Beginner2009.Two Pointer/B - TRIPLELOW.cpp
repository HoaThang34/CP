#include <bits/stdc++.h>
using namespace std;
long long n, x;
vector <long long> a;

#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> x;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  long long d = 0;
  sort(a.begin() + 1, a.end());
  for (int i = 1; i <= n; i++){
    long long l = i + 1, r = n;
    while (l < r){
      long long sum = a[i] + a[l] + a[r];
      if (sum <= x){
        d += r - l;
        l++;
      }
      else r--;
    }
  }
  cout << d;
  return 0;
}
