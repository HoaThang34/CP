/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define nap "HOPQUA"
int n, d;
vector <int> a;

void hoathang(){
    cin >> n >> d;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin() + 1, a.begin() + n + 1);
    int ans = 0, pos = 1;
    for (int i = 1; i <= n; i++){
        pos = max(pos, i + 1);
        while (pos <= n && a[pos] <= a[i] + d){
            pos++;
        }
        int cnt = pos - i - 1;
        if (cnt >= 2){
            ans += cnt*(cnt - 1) /2;
        }
    }
    cout << ans << endl;
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
