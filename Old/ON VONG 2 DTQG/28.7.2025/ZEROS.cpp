#include <bits/stdc++.h>
using namespace std;
long long a, b;
bool check(long long a, long long b, long long k){
  for (long long i = a; i <= b; i++){
    if (k % i != 0){
      return false;
    }
  }
  return true;
}
#define task "ZEROS"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  cin >> a >> b;
  long long i = 0;
  while (check(a, b, i)){
    i++;
  }
  cout << i;
  return 0;
}
