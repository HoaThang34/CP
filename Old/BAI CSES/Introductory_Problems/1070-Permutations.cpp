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
    if (n == 1){
        cout << 1;
        return 0;
    }
    else if (n == 2 || n == 3){
        cout << "NO SOLUTION";
        return 0;
    }
    for (int j = 2; j <= n; j+=2){
        cout << j << " ";
    }
    for (int i = 1; i <= n; i+=2){
        cout << i << " ";
    }
    return 0;
}