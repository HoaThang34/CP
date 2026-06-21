#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector <long long> a;
vector <long long> BIT;
void update(long long i, long long val){
  while (i <= n){
    BIT[i] += val;
    i += i & (-i);
  }
}
long long xuli(long long i){
  long long sum = 0;
  while (i >= 1){
    sum += BIT[i];
    i -= i & (-i);
  }
  return sum;
}
#define task "FW1"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n;
  a.resize(n + 1);
  BIT.resize(n + 1, 0);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
    update(i, a[i]);
  }
  cin >> q;
  while (q--){
    long long l, r;
    cin >> l >> r;
    cout << xuli(r) - xuli(l - 1) << endl;
  }
  return 0;
}
