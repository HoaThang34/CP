#include <bits/stdc++.h>
#define nhap "BAI382"
#define N
#define M
#define fi first
#define se second
#define pb push_back
#define el "\n"
#define ll long long
#define int ll
using namespace std;
void fre(){
    if (!fopen(nhap".inp", "r")) return;
    freopen(nhap".inp", "r", stdin);
    freopen(nhap".out", "w", stdout);
}
ll n;
void trau(){
    int cnt = 0;
    for (int i = 1; i <= n; i++){
        string s = to_string(i);
//        if (s.back() == '0') continue;
        reverse(s.begin(), s.end());
        int j = stoi(s);
        if (j % 2 == 0){
//            cout << i << " ";
            cnt++;
        }
    }
    cout << el << cnt;
}
int getlen(ll num){
    int cnt = 0;
    while (num > 0){
        cnt++;
        num /= 10;
    }
    return cnt;
}
ll solveforlower(int len){
    if (len == 0) return 0;
    ll cnt = 4;
    ll cur = 10;
    for (int l = 2; l <= len; l++){
        cnt += 4 * cur;
        cur *= 10;
    }
    return cnt;
}
ll solveforequal(ll num){
    string s = to_string(num);
    if (s[0] == '1') return 0;
    ll Res = 0;
    ll p = 1;
    for (int i = 1; i < s.size(); i++) {
        p *= 10;
    }
    for (int i = 2; i < (s[0] - '0'); i += 2){
        Res += p;
    }
    ll cnt = 0;
    if ((s[0] - '0') % 2 == 0){
        cnt = 0;
        for (int i = 1; i < s.size(); i++) {
            // cnt *= 1ll * (s[i] - '0') + 1;
            cnt = cnt * 10 + (s[i] - '0');
        }
        Res += (cnt + 1);
    }
    return Res;
}
signed main(void){
    cin.tie(0)->sync_with_stdio(0);
    fre();
    cin >> n;
    cout << solveforlower(getlen(n) - 1) + solveforequal(n);
//    trau();
//    cerr << solveforlower(getlen(n) - 1) << " " << solveforequal(n);
    return 0;
}
