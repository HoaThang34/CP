/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "EMAIL" 

bool check(string s) {
    int n = s.length();
    if (n > 100) return false;
    
    string suffix = "@school.edu.vn";
    int sn = suffix.length();
    
    if (n <= sn) return false;
    
    if (s.substr(n - sn) != suffix) return false;
    
    string name = s.substr(0, n - sn);
    int m = name.length();
    
    if (m < 3 || m > 20) return false;
    
    for (int i = 0; i < m; i++) {
        if (!isalnum(name[i])) return false;
    }
    
    return true;
}

void hoathang(){
    int s;
    if (!(cin >> s)) return;
    int cnt = 0;
    while (s--) {
        string email;
        cin >> email;
        if (check(email)) cnt++;
    }
    cout << cnt << endl;
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