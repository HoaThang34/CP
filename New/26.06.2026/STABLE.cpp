/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;

#define nap "STABLE"
#define endl '\n'
#define int long long
int n;
vector<int> a;
bool check(int l, int r){
    bool ok1 = false, ok2 = false, ok3 = false;
    if (a[l] < 0) ok1 = true;
    if (a[l] == 0) ok2 = true;
    if (a[l] > 0) ok3 = true;
    for (int i = l + 1; i <= r; i++){
        if ((a[i] > 0 && a[i - 1] > 0) || (a[i] < 0) && a[i - 1] < 0) return false;
        if (a[i] == a[i - 1]){
            return false;
        }
        if (a[i] < 0) ok1 = true;
        if (a[i] == 0) ok2 = true;
        if (a[i] > 0) ok3 = true;
    }
    if (ok1 && ok2 && ok3) return true;
    return false;
}
void sub1(){
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 2; j <= n; j++){
            if (check(i,j)){
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
}
void sub2(){
    int l = 1, ans = 0;
    for (int r = 1; r <= n; r++){
        while(!check(l, r) && l < r - 2){
            l++;
            // cerr << l << ' ' << r << endl;
        }
        if (check(l, r))
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    // for (int i = 1; i <= n; i++){
    //     cerr << a[i] << ' ';
    // }
    // sub1();
    sub2();
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
