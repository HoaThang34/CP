/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
void hoathang(){
    long long n, k;
    cin >> n >> k;
    map<long long, vector<long long>> s, t;
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        s[x % k].push_back(x);
    }
    for (int i = 0; i < n; i++){
        long long x;
        cin >> x;
        t[x % k].push_back(x);
    }
    bool ok = true;
    if (s.size() != t.size()){ // Neu so luong phan du khac nhau la sai luon
        ok = false;
    } else {
        for (auto it : s){
            long long du = it.first;
            vector<long long> vs = it.second;
            if (t.find(du) == t.end()){ // Kiem tra xem phan du nay co trong T khong
                ok = false;
                break;
            }
            vector<long long> vt = t[du];
            if (vs.size() != vt.size()){ // So luong phan tu trong "gia dinh" phai giong nhau
                ok = false;
                break;
            }
            sort(vs.begin(), vs.end()); // Sap xep de kiem tra hoan vi
            sort(vt.begin(), vt.end());
            if (vs != vt){ // Neu sau sap xep ma khac nhau thi khong the bien doi
                ok = false;
                break;
            }
        }
    }
    if (ok){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t = 1;
    cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}