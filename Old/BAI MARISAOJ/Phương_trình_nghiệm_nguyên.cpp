#include <bits/stdc++.h>
using namespace std;
long long a, b;

#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> a >> b;
    if (a == 0){
        if (b == 0){          
            cout << "INFINITE SOLUTIONS";
            return 0;
        }
        else{
            cout << "NO SOLUTION";
            return 0;
        }
    }
    else{
        if (b % a == 0){

            b = 0 - b;
            cout << b / a;    
        }
        else cout << "NO SOLUTION";
    }
    return 0;
}