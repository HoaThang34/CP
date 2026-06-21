/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "hoathang" 

void hoathang(){
    string s;
    if(!getline(cin, s)) return;
    stringstream ss(s);
    string t;
    vector<string> v;
    while(ss >> t){
        for(int i = 0; i < t.size(); i++) t[i] = tolower(t[i]);
        v.push_back(t);
    }
    if(v.empty()) return;
    v[0][0] = toupper(v[0][0]);
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << (i == v.size() - 1 ? "" : " ");
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