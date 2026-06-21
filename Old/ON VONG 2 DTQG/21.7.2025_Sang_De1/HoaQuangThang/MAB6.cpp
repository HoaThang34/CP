#include <bits/stdc++.h>
using namespace std;
#define task "MAB6"
long long n;
long long k1 = 0, k2 = 0;
long long res = LLONG_MAX;
void xuli(long long u){
  while (u % 2 == 0 && u > 0){
    k1++;
    u/=2;
  }
  while (u % 5 == 0 && u > 0){
    k2++;
    u/=5;
  }
  // res = min(k1, k2);
}
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; i++){
      xuli(i);
    }
    res = min(k1, k2);
    cout << res;
    return 0;
}