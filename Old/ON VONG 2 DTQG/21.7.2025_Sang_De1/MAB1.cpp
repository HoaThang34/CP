#include <bits/stdc++.h>
using namespace std;
long long n;
#define task "MAB1"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    set<long long> c;
    long long i = 2; 
    while (i <= sqrt(n)){
      if(n % i == 0){
        c.insert(i);
        n/=i;
      }
    }
    if (n > 1) c.insert(n);
    cout << c.size();
    return 0;
}