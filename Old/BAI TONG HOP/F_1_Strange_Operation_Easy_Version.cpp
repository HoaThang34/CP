/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>

using namespace std;
#define endl '\n'

#define nap ""

int n;
vector<int> p;
int dem;

void hoathang(){
    cin >> n;
    p.resize(n);
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++){
        cin >> p[i];
        pos[p[i]] = i;
    }
    dem = 0;
    for (int i = 0; i < n; i++){
        while (true) {
            int val = p[i];
            if (val <= 2) {
                break;
            }
            int pos_val_minus_1 = pos[val - 1];
            int pos_val_minus_2 = pos[val - 2];
            int j = min(pos_val_minus_1, pos_val_minus_2);
            int k = max(pos_val_minus_1, pos_val_minus_2);
            if (i < j){
                dem++;
                p[i] = val - 2;
                p[j] = val;
                p[k] = val - 1;
                pos[val - 2] = i;
                pos[val] = j;
                pos[val - 1] = k;
            }
            else {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << p[i] << " ";
    }
    cout << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap ".inp", "r")){
        freopen(nap ".inp", "r", stdin);
        freopen(nap ".out", "w", stdout);
    }
    int t;
    // t = 1;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}