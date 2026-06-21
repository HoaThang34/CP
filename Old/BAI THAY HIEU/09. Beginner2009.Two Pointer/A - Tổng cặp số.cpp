#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
long long q;

#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  sort(a.begin() + 1, a.end());
  cin >> q;
  while (q--){
    long long x;
    cin >> x;
    long long d = 0;
    long long l = 1, r = n;
    while (l < r){
      long long sum = a[l] + a[r];
      if (sum <= x){
        d += r - l;
        l++;
      }
      else{
        r--;
      }
    }
    cout << d << endl;
  }
  return 0;
}

