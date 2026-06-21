/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "SAFE"
int n;
string s;
bool check(string s){
    bool ok1 = false, ok2 = false, ok3 = false;
    for (char x : s){
        if (x >= 'A' && x <= 'Z'){
            ok1 = true;
        }
        if (x >= 'a' && x <= 'z'){
            ok2 = true;
        }
        if (x >= '0' && x <= '9'){
            ok3 = true;
        }
    }
    if (ok1&&ok2&&ok3){
        return true;
    }
    else return false;
}
void sub1(){
    if (check(s)){
        cout << 1 << endl;
    }
    else cout << 0 << endl;
}
void sub2(){
    long long d = 0;
    for (int i = 0; i <= n - 1; i++){
        for (int j = i; j <= n - 1; j++){
            int len = j - i + 1;
            if (len >= 6){
                string s1 = s.substr(i, len);
                if (check(s1)){
                    d++;
                }
            }
        }
    }
    cout << d << endl;
}
void sub3(){
    long long d = 0;
    int p1 = -1, p2 = -1, p3 = -1;
    for (int i = 0; i < n; i++){
        char x = s[i];
        if (x >= '0' && x <= '9'){
            p1 = i;
        }
        else if (x >= 'a' && x <= 'z'){
            p2 = i;
        }
        else if (x >= 'A' && x <= 'Z'){
            p3 = i;
        }
        int len = i - 5;
        if (len >= 0){
            int rmin = min({p1, p2, p3, len});
            if (rmin >= 0) d += rmin + 1;
        }
    }
    cout << d << endl;
}
void hoathang(){
    cin >> n >> s;
//    sub1();
//    sub2();
//    sub3();
    if (n == 6){
        sub1();
    }
    else if (n <= 100){
        sub2();
    }
    else sub3();
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
