#include <bits/stdc++.h>
using namespace std;
long long n, m, x;
vector <long long> a;
// long long xuli(long long x){
//   long long d = 0;
//   long long l = 1, r = n;
//   while (l <= r){
//     long long mid = (l + r)/2;
//     if (a[mid] == x){
//       d++;
//       r = mid - 1;
//       // l = mid + 1;
//     }
//     else if (a[mid] < x){
//       l = mid + 1;
//     }
//     else r = mid - 1;
//   }
//   return d;
// }
#define task "sol"
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
  sort(a.begin() + 1, a.end());
  while (m--){
    cin >> x;
    long long l = lower_bound(a.begin(), a.end(), x) - a.begin();
    long long r = upper_bound(a.begin(), a.end(), x) - a.begin();
    cout << r - l << endl;

  }
  return 0;
}
