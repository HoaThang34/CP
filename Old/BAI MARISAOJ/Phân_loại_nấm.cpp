#include <bits/stdc++.h>
using namespace std;
float n;
#define task "sol"
signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n;
    if (n >= 9){
        cout << "VERY TOXIC";
        return 0;
    }
    else if (n >= 5){
        cout << "TOXIC";
        return 0;
    }
    else{
        cout << "SAFE";
        return 0;
    }
    return 0;
}