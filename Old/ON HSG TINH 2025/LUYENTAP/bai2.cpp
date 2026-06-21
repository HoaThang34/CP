/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MAXN = 1e6 + 5;
#define nap "bai2"
string s;
vector <long long> f(MAXN, 1);
void sang(){
    f[0] = f[1] = 0;
    for (int i = 2; i*i <= MAXN; i++){
        if (f[i] == 1){
            for (int j = i*i; j <= MAXN; j+=i){
                f[j] = 0;
            }
        }
    }
}
void hoathang(){
    sang();
    cin >> s;
    vector <long long> ans;
    string s1 = "";
    for (char x : s){
        if (isdigit(x)){
            s1 += x;
        }
        else if (s1.size() > 0){
            long long k = stoll(s1);
            ans.push_back(k);
            s1 = "";
        }
    }
    if (s1.size() > 0){
        long long k = stoll(s1);
        ans.push_back(k);
    }
    sort(ans.rbegin(), ans.rend());
    for (long long x : ans){
        if (f[x] == 1){
            cout << x << endl;
            return;
        }
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
