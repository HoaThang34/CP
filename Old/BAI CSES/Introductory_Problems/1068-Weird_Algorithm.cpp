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
    while (n != 1){
        cout << n << ' ';
        if (n % 2 == 0){
            n /= 2;
            
        }
        else{
            n *= 3;
            n++;
        }
    }
    cout << 1;
 
    return 0;