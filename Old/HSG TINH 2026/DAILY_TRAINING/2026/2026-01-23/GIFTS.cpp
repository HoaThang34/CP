/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "GIFTS"
int n, k, q, l, r, x;
unordered_map<int, int> cnt;
void sub1(){
    while (k--){
        cin >> l >> r;
        for (int i = l; i <= r; i++){
            cnt[i]++;
        }
    }
    while (q--){
        cin >> x;
        cout << cnt[x] << endl;
    }
}
void sub2(){
    vector <int> a, b;
    while (k--){
        cin >> l >> r;
        a.push_back(l);
        b.push_back(r);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (q--){
        cin >> x;
        int d1 = upper_bound(a.begin(), a.end(), x) - a.begin();
        int d2 = lower_bound(b.begin(), b.end(), x) - b.begin();
        cout << d1 - d2 << endl;
    }
}
void hoathang(){
    cin >> n >> k >> q;
//    sub1();
//    sub2();
    if (n <= 1000 && k <= 1000 && q <= 1000){
        sub1();
    }
    else sub2();
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
