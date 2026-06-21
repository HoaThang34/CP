/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "MATKHAU"
string s;
bool check(string ss, string s){
    if (s.size() % ss.size() != 0) return false;
    for (int i = 0; i < s.size(); i++){
        if (s[i] != ss[i % ss.size()]){
            return false;
        }
    }
    return true;
}
void hoathang(){
    cin >> s;
    int n = s.size();
    vector <int> ans;
    for (int i = 1; i*i <= n; i++){
        if (n % i == 0){
            ans.push_back(i);
            if (i != n/i){
                ans.push_back(n/i);
            }
        }
    }
    sort(ans.begin(), ans.end());
        string ss = "";
    for (int x : ans){
        string k = s.substr(0, x);
        if (check(k, s)){
            ss = k;
            break;
        }
    }
    map<char,int> cnt;
    int rmax = 0;
    for (char x : ss){
        cnt[x]++;
        rmax = max(rmax, cnt[x]);
    }
    cout << rmax << endl;
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
