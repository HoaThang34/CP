#include <bits/stdc++.h>
using namespace std;
vector <bool> f(1e6+5, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i <= sqrt(1e6); i++){
        if (f[i]){
            for (int j = i * i; j <= 1e6; j += i){
                f[j] = false;
            }
        }
    }
}
long long sum(long long n){
  long long s = 0;
  while (n != 0){
    s += n % 10;
    n /= 10;
  }
  return s;
}
bool check (long long n){
  string s = to_string(n);
  string s1 = s;
  reverse(s1.begin(), s1.end());
  if (s == s1 && f[sum(n)]){
    return true;
  }
  return false;
}
#define task "PALINPRIME"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  sang();
  long long l, r;
  long long d = 0;
  cin >> l >> r;
  for (long long i = l; i <= r; i++){
    if (check(i)) d++;
  }
  cout << d;
  return 0;
}

