/*
    author: hoaquangthang
*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define nap "bai2"
string s;
int sum;

void hoathang(){
    cin >> s;
    sum = 0;
    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i])) {
            sum += s[i] - '0';
        }
    }
    if (sum % 2 == 0)
        cout << "Hard" << sum;
    else
        cout << "Easy" << sum;
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
