/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "NICE"
int n;
vector <int> a;
//bool check(vector <int> a){
//    if (a[1] == a.size() - 1) return true;
//    else return false;
//}

void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    int rmax = 0;
    for (int i = 1; i <= n; i++){
        if (a[i] <= n - i){
            rmax = max(rmax, a[i]);
        }
    }
    cout << n - rmax - 1 << endl;
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
