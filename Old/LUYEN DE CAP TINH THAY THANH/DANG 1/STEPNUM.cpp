///*
//    author: hoaquangthang
//*/
//#include <bits/stdc++.h>
//using namespace std;
//
//#define endl '\n'
//#define nap "STEPNUM"
//long long l, r;
//bool check1(long long n){
//    int last = -1;
//    while (n){
//        if (last != -1 && last <= n % 10){
//            return false;
//        }
//        last = n % 10;
//        n/=10;
//    }
//    return true;
//}
//bool check2(long long n){
//    int last = -1;
//    while (n){
//        if (last != -1 && last >= n % 10){
//            return false;
//        }
//        last = n % 10;
//        n/=10;
//    }
//    return true;
//}
//void sub1(){
//    long long d = 0;
//    for (long long i  = l; i <= r; i++){
//        if (check1(i)||check2(i)){
//            d++;
//        }
//    }
//    cout << d << endl;
//}
//void hoathang(){
//    cin >> l >> r;
//    sub1();
//}
//
//signed main(){
//    ios_base::sync_with_stdio(0); cin.tie(0);
//    if (fopen(nap".inp", "r")){
//        freopen(nap".inp", "r", stdin);
//        freopen(nap".out", "w", stdout);
//    }
//    hoathang();
//    return 0;
//}



/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

vector<long long> a;

void gen(){
    for (int m = 1; m < (1 << 10); m++){
        long long x = 0;
        bool ok = 1;
        for (int d = 0; d <= 9; d++){
            if (m & (1 << d)){
                if (x == 0 && d == 0){ ok = 0; break; }
                x = x * 10 + d;
            }
        }
        if (ok) a.push_back(x);
        x = 0; ok = 1;
        for (int d = 9; d >= 0; d--){
            if (m & (1 << d)){
                if (x == 0 && d == 0){ ok = 0; break; }
                x = x * 10 + d;
            }
        }
        if (ok) a.push_back(x);
    }
}

void hoathang(){
    long long l, r;
    cin >> l >> r;
    gen();
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    cout << upper_bound(a.begin(), a.end(), r)
       - lower_bound(a.begin(), a.end(), l);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    hoathang();
    return 0;
}

