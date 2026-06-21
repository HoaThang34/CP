/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long N = 5 * 1e6 + 5;
#define nap "bai2"
string s;
vector <bool> f(N, true);
void sang(){
    f[0] = f[1] = false;
    for (int i = 2; i * i <= N; i++){
        if (f[i]){
            for (int j =i *i; j <= N; j+=i){
                f[j] = false;
            }
        }
    }
}
bool cmp (long long a, long long b){
    return a > b;
}
void hoathang(){
    sang();
    cin >> s;
    long long n = s.size();
    string dg = "";
    vector <long long> ans;
    for (int i = 0; i <= n - 1; i++){
        if (isdigit(s[i])){
            dg += s[i];
        }
        else if (!dg.empty()){
            ans.push_back(stoi(dg));
            dg = "";
        }
    }
    if (!dg.empty()){
        ans.push_back(stoi(dg));
    }
    sort(ans.begin(), ans.end(), cmp);
//    for (long long x : ans) cout << x << ' ';
    for (long long x : ans){
        if (f[x]){
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
