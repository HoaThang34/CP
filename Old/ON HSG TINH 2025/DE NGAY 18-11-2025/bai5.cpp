/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai5"
int n, l, w, h;
vector<pair<int, int>> a;
bool check(int x){
    vector<vector<int>> f(l + 2, vector<int>(l + 2, 0));
    for (int i = 1; i <= x; i++){
        f[a[i].first + 1][a[i].second + 1] = 1;
    }
    for (int i = 1; i <= l + 1; i++){
        for (int j = 1; j <= l + 1; j++){
            f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
        }
    }
    for (int i = 0; i <= l - w; i++){
        for (int j = 0; j <= l - h; j++){
            int x1 = i + 1, y1 = j + 1;
            int x2 = i + w, y2 = j + h;
            int cnt = f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
            if (cnt == 0){
                return false;
            }
        }
    }
    return true;
}
void hoathang(){
    cin >> n >> l >> w >> h;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i].first >> a[i].second;
    }
    int le = 1, r = n, ans = -1;
    while (le <= r){
        int mid = le + (r - le) / 2;
        if (check(mid)){
            ans = mid;
            r = mid - 1;
        }
        else
            le = mid + 1;
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
