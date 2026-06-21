/*
    author: hoaquangthang
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define nap "bai4"
string s;
void hoathang(){
    cin >> s;
    bool ok = 0;
    deque<char> dq;
    for (char x : s){
        if (!ok) dq.push_back(x);
        else dq.push_front(x);
        ok = !ok;
    }
    string ans = "";
    for (char x : dq)
        ans += x;
    if (!ok)
        cout << ans << endl;
    else{
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
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
