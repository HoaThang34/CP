/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
#define endl '\n'
#define nap "CAU2"
int n;
vector <int> cnt(N, 0);
void hoathang(){
    cin >> n;
    int rmax = 0;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        cnt[x]++;
        rmax = max(rmax, cnt[x]);
    }
    cout << rmax << endl;
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
