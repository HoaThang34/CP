/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap ""
bool la_doi_xung(const string& s){
    string tmp = s;
    reverse(tmp.begin(), tmp.end());
    return s == tmp;
}
void hoathang(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    long long trai = 0, phai = n - 1;
    while (trai < phai && s[trai] == s[phai]){
        trai++;
        phai--;
    }
    if (trai >= phai){
        cout << 0 << endl << endl;
        return;
    }
    vector<long long> p1, p2;
    string x1, x2;
    for (int i = 0; i < n; i++){
        if (i >= trai && i <= phai && s[i] == s[trai]){
            p1.push_back(i + 1);
        } else {
            x1 += s[i];
        }
        if (i >= trai && i <= phai && s[i] == s[phai]){
            p2.push_back(i + 1);
        } else {
            x2 += s[i];
        }
    }
    if (la_doi_xung(x1)){
        cout << p1.size() << endl;
        for (int i = 0; i < (int)p1.size(); i++){
            cout << p1[i] << (i == (int)p1.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else if (la_doi_xung(x2)){
        cout << p2.size() << endl;
        for (int i = 0; i < (int)p2.size(); i++){
            cout << p2[i] << (i == (int)p2.size() - 1 ? "" : " ");
        }
        cout << endl;
    } else {
        cout << -1 << endl;
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