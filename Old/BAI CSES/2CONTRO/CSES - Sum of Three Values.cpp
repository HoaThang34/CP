#include <bits/stdc++.h>
using namespace std;
long long n, s;
vector <pair<long long, long long>> a;

#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> s;
  a.resize(n + 1);
  for (int i = 1; i <= n; i++){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort (a.begin(), a.end());
  for (int i = 1; i <= n; i++){
    long long l = i + 1, r = n;
    while (l < r){
      long long sum = a[i].first + a[l].first + a[r].first;
      if (s == sum){
        cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second;
        return 0;
      }
      else if (sum < s){
        l++;
      }
      else r--;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}

