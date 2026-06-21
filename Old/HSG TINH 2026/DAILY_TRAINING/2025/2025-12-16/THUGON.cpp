/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define nap "THUGON"
string s;
void hoathang(){
    while (cin >> s){
        string ans = "";
        int n = s.size();
        int i = 0;
        while(i < n){
            char c = s[i];
            int cnt = 0;
            int j = i;
            while (j < n && s[j] == c){
                cnt++; j++;
            }
            if (cnt > 1){
                ans += to_string(cnt);
            }
            ans += c;
            i = j;
        }
        cout << ans << endl;
    }
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
