/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "CAU3"
string s;
bool check(string s){
    unordered_map<int, int> cnt;
    for (char x : s){
        if (cnt[x] > 0){
            return false;
        }
        cnt[x]++;
    }
    return true;
}
void hoathang(){
    cin >> s;
    if (check(s)) cout << 1 << endl;
    else{
        unordered_map<int, int> cnt;
        int d = 1;
        int l = 0;
        for (int r = 0; r < s.size(); r++){
            if (cnt[s[r]] > 0){
                d++;
                l = r;
                cnt.clear();
            }
            cnt[s[r]]++;
        }
        cout << d<< endl;
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
