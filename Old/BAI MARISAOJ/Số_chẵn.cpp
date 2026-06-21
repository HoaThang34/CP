#include <bits/stdc++.h>
using namespace std;
long long n;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    if (n % 2 == 1) n--;
    while (n > 0){
        cout << n << ' ';
        n = n - 2;

    }
    
    return 0;
}