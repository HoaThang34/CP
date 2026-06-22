/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "DSK_DSC"
#define endl '\n'
#define int long long
int n;
void hoathang(){
    cin >> n;
    int k;
    for (int i = 1; i <= n; i++){
        string s;
        getline(cin, s);
        stringstream ss(s);
        while (ss >> k){
//            cout << k << ' ';
            if (i - 1 < k) cout << i - 1 << ' ' << k << endl;
        }
//        cout << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }

    hoathang();

    return 0;
}
