#include <bits/stdc++.h>
using namespace std;
long long n, q;
vector <long long> a;
vector <long long> vs;
void subtask1(){
    vs.assign(n + 1, false);
    long long l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++){
      vs[i] = true;
    }
    vector <long long> b;
    for (int i = 1; i <= n; i++){
      if (!vs[i]) b.push_back(a[i]);  
    }
    if (b.size() == 1) cout << b[0] << endl;
    else{
      sort(b.begin(), b.end());
      if (b.size() % 2 == 0) cout << b[b.size()/2 - 1] << endl;
      else cout << b[b.size()/2] << endl;
    }
}
void subtask2(){
  long long l, r;
  cin >> l >> r;
  long long len = n - (r - l + 1);
  long long pos = (len + 1)/2;
  long long le = l - 1;
  long long ri = n - r;
  if (pos <= le) cout << a[pos] << endl;
  else cout << a[r + pos - le] << endl;
}
#define task "sol"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> n >> q;
  a.resize(n + 1);
  vs.resize(n + 1, false);
  for (int i = 1; i <= n; i++){
    cin >> a[i];
  }
  if (n <= 5000 && q <= 5000){
    while (q--){
      subtask1();
    }
  }
  else{
    while (q--){
      subtask2();
    }
  }
  return 0;
}

