/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap ""

long long n, k;
vector <long long> a(1e6 + 5);
vector <string> ans;
void dq(int i){
    if (i > n){
        string s = "";
        for (int j = 1; j <= n; j++){
            s = s + to_string(a[j]);
        }
        ans.push_back(s);
    }
    else{
        for (int j = 0; j <= 1; j++){
            a[i] = j;
            dq(i + 1);
        }
    }
}

void hoathang(){
    cin >> n >> k;
    dq(1);
    for (string x : ans){
        if (x[0] != '1'){
            continue;
        }
        int d = 0;
        for (char c : x){
            if (c == '1'){
                d++;
            }
        }
        if (d <= k){
            cout << x << endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen(nap".inp", "r")){
        freopen(nap".inp", "r", stdin);
        freopen(nap".out", "w", stdout);
    }
    int t;
    t = 1;
    // cin >> t;
    while (t--){
        hoathang();
    }
    return 0;
}