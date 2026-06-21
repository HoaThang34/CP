/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "MATMA"

void hoathang(){
    string s;
    if (!getline(cin, s)) return;
    int n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            cout << ' ';
            continue;
        }
        int j = i;
        while (j < n && s[j] != ' ') j++;
        string t = s.substr(i, j - i);
        string r = t;
        reverse(r.begin(), r.end());
        for (int k = 0; k < t.length(); k++) {
            if (isupper(t[k])) cout << (char)toupper(r[k]);
            else cout << (char)tolower(r[k]);
        }
        i = j - 1;
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