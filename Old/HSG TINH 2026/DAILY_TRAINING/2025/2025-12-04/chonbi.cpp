/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "chonbi"
int n, m;
vector <pair <int, int>> a;
bool cmp(pair <int, int> a, pair <int, int> b){
    return a.first > b.first;
}

void hoathang(){
    cin >> n >> m;
    a.resize(m + 5);
    for (int i = 1; i <= m; i++){
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin() + 1, a.begin() + 1 + m, cmp);
    long long ans = 0;
    for (int i = 1; i <= m; i++){
        if (n == 0)
            break;
        int res = min(n, a[i].second);
        ans += (long long)res * a[i].first;
        n -= res;
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
