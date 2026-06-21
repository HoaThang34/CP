#include <bits/stdc++.h>
using namespace std;
long long t;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        long long y, x;
        cin >> y >> x;
        if (x == 1){
            cout << y*y << endl;
        }
        else if (y == 1){
            cout << x*x << endl;
        }
        else{
            if (y > x){
                if (y % 2 == 0){
                    cout << (y*y)-x+1 << endl;
                }
                else{
                    cout << (y - 1) * (y - 1) + x << endl;
                }
            }
            else{
                if (x % 2 != 0){
                    cout << (x*x)-y+1 << endl;
                }
                else{
                    cout << (x - 1) * (x - 1) + y << endl;
                }
            }
        }
    }
    return 0;
}