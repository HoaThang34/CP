/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "bai2"
int n, m;
vector <long long> a;
void sub1(){
    int d = 0;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            long long n1 = a[i] % m, n2 = a[j] % m;
            if (n1 == n2) d++;
        }
    }
    cout << d << endl;
}
void sub2(){
    int d = 0;
    vector <int> cnt (1e6 + 5, 0);
    for (int i = 1; i <= n; i++){
        int n1 = a[i] % m;
        cnt[n1]++;
    }
    for (int x : cnt){
        if (x <= 1) continue;
        else d += x*(x - 1)/2;
    }
    cout << d << endl;
}
void hoathang(){
    cin >> n >> m;
    a.resize(n + 5);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if (n <= 1000) sub1();
    else sub2();
//    sub2();
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
