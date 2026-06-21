#include <bits/stdc++.h>
using namespace std;
long long a, b, k;
void subtask1(){
  long long d = 0;
  cin >> a >> b >> k;
  for (long long i = a; i <= b; i++){
    for (long long j = a; j <= b; j++){
      long long i1 = i*i;
      long long j1 = j*j*j;
      long long res = abs(i1 - j1);
      if (i1 >= a && i1 <= b && j1 >= a && j1<= b && res <= k){
        d++;
      }
    }
  }
  cout << d;
}
void subtask2(){
  cin >> a >> b >> k;
  int d = 0;
  for (long long i = a; i <= b; i++){
    long long i1 = i*i*i;
    long long j1 = k - i1;
    if (i1 <= a && i1 <= b && j1 >= a && j1 <= b){
      d++;
    }
  }
  cout << d;
}
#define task "density"
signed main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen(task".inp", "r")){
    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);
  }
  subtask1();
  // subtask2();
  return 0;
}
