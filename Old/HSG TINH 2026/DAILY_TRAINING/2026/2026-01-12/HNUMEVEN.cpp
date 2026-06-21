/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "HNUMEVEN"
int n;
vector <int> a;
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    bool ok = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0) ok =false;
    }
    if (ok) cout << "NONE" << endl;
    else{
        sort(a.begin() + 1, a.begin() + n + 1);
        for (int i = 1; i <= n; i++){
            if (a[i]%2 == 0){
                swap(a[i], a[1]);
                break;
            }
        }
        reverse(a.begin() + 1, a.begin() + 1 + n);
        for (int i = 1; i <= n; i++){
            cout << a[i];
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}
