/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CAU2"
#define int long long
int a, b;
int tongcs(int n){
    int s = 0;
    while (n){
        s += n%10;
        n/=10;
    }
    return s;
}
int gcd(int a, int b){
    int tmp;
    while (b){
        tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;
}
void sub1(){
    int ans = 0;
    for (int i = 1; i <= max(a, b); i++){
        if (a % i == 0 && b % i == 0){
            ans = max(ans, tongcs(i));
        }
    }
    cout << ans << endl;
}
void sub2(){
    int n = gcd(a, b);
    vector <int> ans;
    for (int i = 1; i*i <= n; i++){
        if (n%i == 0){
            ans.push_back(i);
            if (i != n/i){
                ans.push_back(n/i);
            }
        }
    }
    int res = 0;
    for (int x : ans){
        res = max(res, tongcs(x));
    }
    cout << res << endl;
}
void hoathang(){
    cin >> a >> b;
//    sub1();
//    sub2();
    if (a <= 1e6 && b <= 1e6) sub1();
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
