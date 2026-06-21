#include <bits/stdc++.h>
using namespace std;
long long n;
vector <long long> a;
#define task "FW3"
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
  for (int i = 1; i <= n; i++){
    long long d = 0;
    for (int j = 1; j <= i; j++){
      if (a[j] < a[i]) d++;
    }
    cout << d << ' ';
  }
  return 0;
}
