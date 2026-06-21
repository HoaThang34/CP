/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "MAGIC"
int n, q, x, y;
vector <int> a, b;
void sub1(){
    vector<int> aa, bb;
    for (int i = 1; i <= x; i++){
        aa.push_back(a[i]);
        bb.push_back(b[i]);
    }
    sort(aa.begin(), aa.end());
    sort(bb.begin(), bb.end());
    bool ok = true;
    for (int i = 0 ; i < n; i++){
         if (aa[i]!=bb[i]){
            ok = false;
         }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}
void sub2(){
    set<int> st1, st2;
    for (int i = 1; i <= x; i++){
        st1.insert(a[i]);
    }
    for (int i = 1; i <= y; i++){
        st2.insert(b[i]);
    }
    if (st1 == st2){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}
void hoathang(){
    cin >> n;
    a.resize(n + 5);
    b.resize(n + 5);
    unordered_map<int, int> cnt_check;
    bool s1 = true;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        cnt_check[a[i]]++;
        if (cnt_check[a[i]] >= 2){
            s1 =false;
        }
    }
    cnt_check.clear();
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        if (cnt_check[a[i]] >= 2){
            s1 =false;
        }
    }
    cin >> q;
    while(q--){
        cin >> x >> y;
//        if (x == y && s1){
//            sub1();
//        }
//        else{
//            sub2();
//        }
        sub2();
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
