/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
void hoathang(){
    long long n;
    cin >> n;
    if (n == 2){
        cout << -1 << " " << 2 << endl;
        return;
    }
    if (n == 3){
        cout << -1 << " " << 3 << " " << -1 << endl;
        return;
    }
    // Với n >= 4, quy luật -1, 3, -1, 3... là tối ưu nhất
    // Mình chia trường hợp n chẵn và lẻ để code đơn giản hơn
    if (n % 2 == 0){
        for (int i = 1; i <= n / 2; ++i){
            cout << -1 << " " << 3 << " ";
        }
        cout << endl;
    } else {
        for (int i = 1; i <= n / 2; ++i){
            cout << -1 << " " << 3 << " ";
        }
        cout << -1 << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}