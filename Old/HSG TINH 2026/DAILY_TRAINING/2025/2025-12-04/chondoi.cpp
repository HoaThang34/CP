/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "chondoi"

int n;
void hoathang(){
    cin >> n;
    map<char, long long> cnt;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        cnt[s[0]]++;
    }
    vector<long long> a;
    a.push_back(cnt['H']);
    a.push_back(cnt['S']);
    a.push_back(cnt['G']);
    a.push_back(cnt['P']);
    a.push_back(cnt['T']);
    long long ans = 0;
    for (int i = 0; i < 5; i++){
        for (int j = i + 1; j < 5; j++){
            for (int k = j + 1; k < 5; k++){
                ans += a[i] * a[j] * a[k];
            }
        }
    }
    cout << ans << endl;
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
