/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "BOPHIEU"
int n;
vector<int> cnt;
void hoathang(){
    cin >> n;
    cnt.resize(n + 5);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char x;
            cin >> x;
            if (x == 'X'){
                cnt[j]++;
            }
        }
    }
    long long rmax = -1e18;
    for (int i = 1; i <= n; i++) rmax = max(rmax, (long long)cnt[i]);
    int dem = 0;
    for (int i = 1; i <= n; i++){
        if (cnt[i] == rmax){
            dem++;
        }
    }
    cout << dem << ' ' << rmax << endl;
    for (int i = 1; i <= n; i++){
        if (cnt[i] == rmax) cout << i << ' ';
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
