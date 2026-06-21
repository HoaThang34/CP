/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N = 1e6 + 5;
#define nap "tangqua"
int n;

void hoathang(){
    cin >> n;
    vector <int> f(N, 0);
    for (int i = 1; i <= N; i++){
        for (int j = i; j <= N; j+=i){
            f[j] +=i;
        }
    }
    vector <int> ans;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (f[x] - x == x){
            ans.push_back(x);
        }
    }
    cout << ans.size() << endl;
    for (int x : ans){
        cout << x << ' ';
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
