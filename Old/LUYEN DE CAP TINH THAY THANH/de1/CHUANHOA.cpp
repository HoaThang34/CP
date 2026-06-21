/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang"

void hoathang(){
    string s;
    getline(cin, s);
    int n = s.size();
    string cur;
    vector<string> a;
    for(int i = 0; i <= n; i++){
        if(i < n && isalpha(s[i])){
            cur.push_back(tolower(s[i]));
        }else{
            if(!cur.empty()){
                cur[0] = toupper(cur[0]);
                a.push_back(cur);
                cur.clear();
            }
        }
    }
    for(int i = 0; i < (int)a.size(); i++){
        if(i) cout << ' ';
        cout << a[i];
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
