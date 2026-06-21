/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long N = 1e6 + 5;
#define nap ""

long long n;
vector <long long> a(N);

void quaylui(int i){
    if (i > n){
        int d1 = 0, d2 = 0;
        for (int i = 1; i <= n; i += 2){
            if (a[i] == 1){
                d1++;
            } 
        }
        for (int i = 2; i <= n; i+=2){
            if (a[i] == 1){
                d2++;
            }
        }
        if (d1 == d2){
            for (int i = 1; i <= n; i++){
                cout << a[i];
            }
            cout << endl;
        }
    }
    else{
        for (int j = 0; j <= 1; j++){
            a[i] = j;
            quaylui(i + 1);
        }
    }
}

void hoathang(){
    cin >> n;
    quaylui(1);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}