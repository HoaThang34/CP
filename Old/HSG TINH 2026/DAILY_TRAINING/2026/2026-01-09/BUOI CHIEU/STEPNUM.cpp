/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "STEPNUM"
long long l, r;
bool check1(long long n){
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++){
        if (s[i] <= s[i - 1] && i >= 1){
            return false;
        }
    }
    return true;
}
bool check2(long long n){
    string s = to_string(n);
    for (int i = 0; i < s.size(); i++){
        if (s[i] >= s[i - 1] && i >= 1){
            return false;
        }
    }
    return true;
}
void sub1(){
    long long d = 0;
    for (long long i = l; i <= r; i++){
        if (check1(i) || check2(i)){
//            cerr << i << ' ';
            d++;
        }
    }
    cout << d << endl;
}
void sub2(){

}
void hoathang(){
    cin >> l >> r;
//    sub1();
    if (l <= r && r <= 1e6){
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
